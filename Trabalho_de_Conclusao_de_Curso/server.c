// AJUSTAR CODIGO ...


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
#include <fcntl.h>
#include <sys/time.h>

#define SERV_PORT 4000
#define MAX_CONNECTION	10

#define MAX_COUNT 1000

int main(int argc, char *argv[]){
	int sockfd, connfd, buff_size;
	socklen_t sk_len;
	int received=0;
	struct sockaddr_in addr, cliaddr;
	unsigned char *buff = NULL;

	if (argc != 2) {
		printf("usage: %s <port> <buff_size>\n", argv[0]);
		return 0;
	}
	addr.sin_family = AF_INET;
	addr.sin_port	= htons(atoi(argv[1]));
	addr.sin_addr.s_addr = INADDR_ANY;

	buff_size = (1024*1024*4);//atoi(argv[2]);

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	bind(sockfd, (struct sockaddr *) &addr, sizeof(struct sockaddr_in));
	listen(sockfd, MAX_CONNECTION);

	sk_len = sizeof(addr);

while(1) {
	printf("esperando conexao ...\n");
	if ((connfd = accept(sockfd, (struct sockaddr *) &cliaddr, &sk_len)) == -1){
		perror("connect");
		return -1;
	}

	printf("Conectado com clinte %s...\n", inet_ntoa(cliaddr.sin_addr));

	buff = calloc(1, buff_size);
	if (!buff) {
		perror("calloc");
		exit(0);
	}

	do {
		if ((received = read(connfd, buff, buff_size)) < 0) { // read from socket
			perror("read");
			break;
		}
		//printf("\nbytes received from client: %d", received);
	}while (received > 0);
	close(connfd);
}
	printf("\nfinished .... \n");
	close(connfd);
	return(0);
}
