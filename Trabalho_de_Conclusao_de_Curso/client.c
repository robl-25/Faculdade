#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

/*
medir tempo de envio
  1KB 2KB 4KB 8KB 16KB 32KB 64KB 128KB 256KB 512KB 1MB
*/

#define C 11   // tamanho do buffer da aplicacao: 1KB 2KB 4KB 8KB 16KB 32KB 64KB 128KB 256KB 512KB 1MB
#define L 1000 // tamanho da amostra para cada buff

//#define DATA_SIZE GB // tamano do objeto a ser transferido 1GB

int main(int argc, char *argv[]){

	int sockfd, j=0;
	int sent;
	struct sockaddr_in serv_addr;
	unsigned char *buffer = NULL;
	int buff_size = 0;
	int sample_size = 0;
	int factor = 0;
	int DATA_SIZE;
	if(argc != 6){
		printf("[usage]: %s <server_ip> <server_port> <result_filename> <sample_size> <data_size>\n", argv[0]);
		return 0;
	}


	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi(argv[2]));
	inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

	sockfd = m_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (m_connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(struct sockaddr_in)) == -1){
		printf("can't connect to server\n");
		exit(0);
	}

	FILE *fp = fopen(argv[3], "a+");
	if (!fp) {
		perror("fopen");
		exit(0);
	}
	DATA_SIZE = atoi(argv[5]);
	buffer = calloc(1, DATA_SIZE);
	if (!buffer) {
		perror("calloc");
		exit(0);
	}


	sample_size = atoi(argv[4]);
	double latency, throughput;
	for (j=0; j<sample_size; j++) {
		factor = 1;
		buff_size = 0;
		while (buff_size < DATA_SIZE) {
			buff_size = factor * KB;
			sent = 0;
			gettimeofday(&t_s, NULL);
			 while (sent < DATA_SIZE) {
                if((buff_size+sent) >= DATA_SIZE){
                    if((sent += write(sockfd, buffer, (DATA_SIZE-sent))) < 0) {
                        perror("write");
                        continue;
                    }
                }
                else if((sent += write(sockfd, buffer, buff_size)) < 0) {
                    perror("write");
                    continue;
                }
            }
			gettimeofday(&t_e, NULL);
			timersub(&t_e, &t_s, &t_r);
			latency = misc_timevaltosec(&t_r);
			throughput = (sent/latency)/(KB*1024*1.0);
			printf("\n[%d]: buff_size=%d, sent=%d, ellapsed_time=%g throughput=%g", j, buff_size, sent, latency, throughput);
			fflush(stdout);
			fprintf(fp, "%g\t", latency);
			fflush(fp);
			factor *= 2;
		}
		fflush(fp);
		fprintf(fp, "\n");
	}

	if (buffer){
		free(buffer);
	}

	m_close(sockfd);
	fclose(fp);
	printf("\nfinished .... \n");
	return(0);
}

