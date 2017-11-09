#include <stdio.h>
#include <stdlib.h>

void funcao(void){
	int i, j;
	char aux[50];
	char comando[200];

	

	//homo
	system("tc qdisc change dev eth0 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth1 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth2 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth3 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth4 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	sprintf(aux, "mkdir homo_homo_homo");
	system(aux);

	sleep(2);
	
	sprintf(comando, "tc qdisc change dev eth0 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth0 -vvv -w ./homo_homo_homo/bineth0 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth1 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth1 -vvv -w ./homo_homo_homo/bineth1 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth2 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth2 -vvv -w ./homo_homo_homo/bineth2 &");
	system(comando);
	
	sprintf(comando, "tc qdisc change dev eth3 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth3 -vvv -w ./homo_homo_homo/bineth3 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth4 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth4 -vvv -w ./homo_homo_homo/bineth4 &");
	system(comando);

	sleep(3);
	
	
	printf("\n* Iniciando aplicativo cliente...\n");
	//executa app cliente
	sprintf(comando, "./cliente 192.168.1.1 9000 file.txt 500 3");
	system(comando);
	
	sleep(2);
	
	printf("\n* Fecha TCPDump...\n");
	printf("\n----------------------------\n");
	system("killall -9 tcpdump.4.6.2");

	//homo
	system("tc qdisc change dev eth0 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth1 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth2 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth3 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth4 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
sprintf(aux, "mkdir homo_homo_hete");
	system(aux);

	sleep(2);
	
	sprintf(comando, "tc qdisc change dev eth0 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth0 -vvv -w ./homo_homo_hete/bineth0 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth1 parent 1:1 handle 10: netem loss 0%% latency 10ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth1 -vvv -w ./homo_homo_hete/bineth1 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth2 parent 1:1 handle 10: netem loss 0%% latency 20ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth2 -vvv -w ./homo_homo_hete/bineth2 &");
	system(comando);
	
	sprintf(comando, "tc qdisc change dev eth3 parent 1:1 handle 10: netem loss 0%% latency 40ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth3 -vvv -w ./homo_homo_hete/bineth3 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth4 parent 1:1 handle 10: netem loss 0%% latency 80ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth4 -vvv -w ./homo_homo_hete/bineth4 &");
	system(comando);

	sleep(3);
	
	
	printf("\n* Iniciando aplicativo cliente...\n");
	//executa app cliente
	sprintf(comando, "./cliente 192.168.1.1 9000 file.txt 500 3");
	system(comando);
	
	sleep(2);
	
	printf("\n* Fecha TCPDump...\n");
	printf("\n----------------------------\n");
	system("killall -9 tcpdump.4.6.2");


	//hete

	system("tc qdisc change dev eth0 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth1 root handle 1: tbf limit 10240kb rate 25mbit mtu 1540b peakrate 25.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth2 root handle 1: tbf limit 10240kb rate 50mbit mtu 1540b peakrate 50.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth3 root handle 1: tbf limit 10240kb rate 75mbit mtu 1540b peakrate 75.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth4 root handle 1: tbf limit 10240kb rate 100mbit mtu 1540b peakrate 100.1mbit buffer 512kb");
	

sprintf(aux, "mkdir homo_hete_homo");
	system(aux);

	sleep(2);
	
	sprintf(comando, "tc qdisc change dev eth0 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth0 -vvv -w ./homo_hete_homo/bineth0 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth1 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth1 -vvv -w ./homo_hete_homo/bineth1 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth2 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth2 -vvv -w ./homo_hete_homo/bineth2 &");
	system(comando);
	
	sprintf(comando, "tc qdisc change dev eth3 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth3 -vvv -w ./homo_hete_homo/bineth3 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth4 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth4 -vvv -w ./homo_hete_homo/bineth4 &");
	system(comando);

	sleep(3);
	
	
	printf("\n* Iniciando aplicativo cliente...\n");
	//executa app cliente
	sprintf(comando, "./cliente 192.168.1.1 9000 file.txt 500 3");
	system(comando);
	
	sleep(2);
	
	printf("\n* Fecha TCPDump...\n");
	printf("\n----------------------------\n");
	system("killall -9 tcpdump.4.6.2");


	//hete

	system("tc qdisc change dev eth0 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth1 root handle 1: tbf limit 10240kb rate 25mbit mtu 1540b peakrate 25.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth2 root handle 1: tbf limit 10240kb rate 50mbit mtu 1540b peakrate 50.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth3 root handle 1: tbf limit 10240kb rate 75mbit mtu 1540b peakrate 75.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth4 root handle 1: tbf limit 10240kb rate 100mbit mtu 1540b peakrate 100.1mbit buffer 512kb");
	

sprintf(aux, "mkdir homo_hete_hete");
	system(aux);

	sleep(2);
	
	sprintf(comando, "tc qdisc change dev eth0 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth0 -vvv -w ./homo_hete_hete/bineth0 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth1 parent 1:1 handle 10: netem loss 0%% latency 10ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth1 -vvv -w ./homo_hete_hete/bineth1 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth2 parent 1:1 handle 10: netem loss 0%% latency 20ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth2 -vvv -w ./homo_hete_hete/bineth2 &");
	system(comando);
	
	sprintf(comando, "tc qdisc change dev eth3 parent 1:1 handle 10: netem loss 0%% latency 40ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth3 -vvv -w ./homo_hete_hete/bineth3 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth4 parent 1:1 handle 10: netem loss 0%% latency 80ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth4 -vvv -w ./homo_hete_hete/bineth4 &");
	system(comando);

	sleep(3);
	
	
	printf("\n* Iniciando aplicativo cliente...\n");
	//executa app cliente
	sprintf(comando, "./cliente 192.168.1.1 9000 file.txt 500 3");
	system(comando);
	
	sleep(2);
	
	printf("\n* Fecha TCPDump...\n");
	printf("\n----------------------------\n");
	system("killall -9 tcpdump.4.6.2");


	//homo
	system("tc qdisc change dev eth0 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth1 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth2 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth3 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth4 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	

sprintf(aux, "mkdir hete_homo_homo");
	system(aux);

	sleep(2);
	
	sprintf(comando, "tc qdisc change dev eth0 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth0 -vvv -w ./hete_homo_homo/bineth0 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth1 parent 1:1 handle 10: netem loss 1%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth1 -vvv -w ./hete_homo_homo/bineth1 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth2 parent 1:1 handle 10: netem loss 2%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth2 -vvv -w ./hete_homo_homo/bineth2 &");
	system(comando);
	
	sprintf(comando, "tc qdisc change dev eth3 parent 1:1 handle 10: netem loss 6%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth3 -vvv -w ./hete_homo_homo/bineth3 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth4 parent 1:1 handle 10: netem loss 12%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth4 -vvv -w ./hete_homo_homo/bineth4 &");
	system(comando);

	sleep(3);
	
	
	printf("\n* Iniciando aplicativo cliente...\n");
	//executa app cliente
	sprintf(comando, "./cliente 192.168.1.1 9000 file.txt 500 3");
	system(comando);
	
	sleep(2);
	
	printf("\n* Fecha TCPDump...\n");
	printf("\n----------------------------\n");
	system("killall -9 tcpdump.4.6.2");

	//homo
	system("tc qdisc change dev eth0 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth1 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth2 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth3 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth4 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	

sprintf(aux, "mkdir hete_homo_hete");
	system(aux);

	sleep(2);
	
	sprintf(comando, "tc qdisc change dev eth0 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth0 -vvv -w ./hete_homo_hete/bineth0 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth1 parent 1:1 handle 10: netem loss 1%% latency 10ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth1 -vvv -w ./hete_homo_hete/bineth1 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth2 parent 1:1 handle 10: netem loss 2%% latency 20ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth2 -vvv -w ./hete_homo_hete/bineth2 &");
	system(comando);
	
	sprintf(comando, "tc qdisc change dev eth3 parent 1:1 handle 10: netem loss 6%% latency 40ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth3 -vvv -w ./hete_homo_hete/bineth3 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth4 parent 1:1 handle 10: netem loss 12%% latency 80ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth4 -vvv -w ./hete_homo_hete/bineth4 &");
	system(comando);

	sleep(3);
	
	
	printf("\n* Iniciando aplicativo cliente...\n");
	//executa app cliente
	sprintf(comando, "./cliente 192.168.1.1 9000 file.txt 500 3");
	system(comando);
	
	sleep(2);
	
	printf("\n* Fecha TCPDump...\n");
	printf("\n----------------------------\n");
	system("killall -9 tcpdump.4.6.2");


	//hete

	system("tc qdisc change dev eth0 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth1 root handle 1: tbf limit 10240kb rate 25mbit mtu 1540b peakrate 25.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth2 root handle 1: tbf limit 10240kb rate 50mbit mtu 1540b peakrate 50.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth3 root handle 1: tbf limit 10240kb rate 75mbit mtu 1540b peakrate 75.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth4 root handle 1: tbf limit 10240kb rate 100mbit mtu 1540b peakrate 100.1mbit buffer 512kb");
	

sprintf(aux, "mkdir hete_hete_homo");
	system(aux);

	sleep(2);
	
	sprintf(comando, "tc qdisc change dev eth0 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth0 -vvv -w ./hete_hete_homo/bineth0 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth1 parent 1:1 handle 10: netem loss 1%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth1 -vvv -w ./hete_hete_homo/bineth1 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth2 parent 1:1 handle 10: netem loss 2%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth2 -vvv -w ./hete_hete_homo/bineth2 &");
	system(comando);
	
	sprintf(comando, "tc qdisc change dev eth3 parent 1:1 handle 10: netem loss 6%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth3 -vvv -w ./hete_hete_homo/bineth3 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth4 parent 1:1 handle 10: netem loss 12%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth4 -vvv -w ./hete_hete_homo/bineth4 &");
	system(comando);

	sleep(3);
	
	
	printf("\n* Iniciando aplicativo cliente...\n");
	//executa app cliente
	sprintf(comando, "./cliente 192.168.1.1 9000 file.txt 500 3");
	system(comando);
	
	sleep(2);
	
	printf("\n* Fecha TCPDump...\n");
	printf("\n----------------------------\n");
	system("killall -9 tcpdump.4.6.2");

	//hete

	system("tc qdisc change dev eth0 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth1 root handle 1: tbf limit 10240kb rate 25mbit mtu 1540b peakrate 25.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth2 root handle 1: tbf limit 10240kb rate 50mbit mtu 1540b peakrate 50.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth3 root handle 1: tbf limit 10240kb rate 75mbit mtu 1540b peakrate 75.1mbit buffer 512kb");
	
	system("tc qdisc change dev eth4 root handle 1: tbf limit 10240kb rate 100mbit mtu 1540b peakrate 100.1mbit buffer 512kb");
	

sprintf(aux, "mkdir hete_hete_hete");
	system(aux);

	sleep(2);
	
	sprintf(comando, "tc qdisc change dev eth0 parent 1:1 handle 10: netem loss 0%% latency 5ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth0 -vvv -w ./hete_hete_hete/bineth0 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth1 parent 1:1 handle 10: netem loss 1%% latency 10ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth1 -vvv -w ./hete_hete_hete/bineth1 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth2 parent 1:1 handle 10: netem loss 2%% latency 20ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth2 -vvv -w ./hete_hete_hete/bineth2 &");
	system(comando);
	
	sprintf(comando, "tc qdisc change dev eth3 parent 1:1 handle 10: netem loss 6%% latency 40ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth3 -vvv -w ./hete_hete_hete/bineth3 &");
	system(comando);

	sprintf(comando, "tc qdisc change dev eth4 parent 1:1 handle 10: netem loss 12%% latency 80ms");
	system(comando);
	sprintf(comando, "tcpdump.4.6.2 -p -s96 -i eth4 -vvv -w ./hete_hete_hete/bineth4 &");
	system(comando);

	sleep(3);
	
	
	printf("\n* Iniciando aplicativo cliente...\n");
	//executa app cliente
	sprintf(comando, "./cliente 192.168.1.1 9000 file.txt 500 3");
	system(comando);
	
	sleep(2);
	
	printf("\n* Fecha TCPDump...\n");
	printf("\n----------------------------\n");
	system("killall -9 tcpdump.4.6.2");
}

int main(int argc, char *argv[]){
	int i, j;
	char nome_arq_erro[50];
	char nome_arq[50];
	char aux[50];
	char comando[200];
	int numErroInicial;
	
	if(argc != 2){
		numErroInicial = 0;
	}
	else if(argc == 2){
		numErroInicial = atoi(argv[1]);
	}
	
	printf("\n### Iniciando o script de experimentos do MPTCP ###\n");

	system("tc qdisc add dev eth0 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	system("tc qdisc add dev eth0 parent 1:1 handle 10: netem loss 0%");
	
	system("tc qdisc add dev eth1 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	system("tc qdisc add dev eth1 parent 1:1 handle 10: netem loss 0%");
	
	system("tc qdisc add dev eth2 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	system("tc qdisc add dev eth2 parent 1:1 handle 10: netem loss 0%");
	
	system("tc qdisc add dev eth3 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	system("tc qdisc add dev eth3 parent 1:1 handle 10: netem loss 0%");
	
	system("tc qdisc add dev eth4 root handle 1: tbf limit 10240kb rate 10mbit mtu 1540b peakrate 10.1mbit buffer 512kb");
	system("tc qdisc add dev eth4 parent 1:1 handle 10: netem loss 0%");

	system("sysctl -w net.ipv4.tcp_congestion_control=lia");
	
	funcao();
	
	system("mv homo_homo_homo/ LIA/");
	system("mv homo_homo_hete/ LIA/");
	system("mv homo_hete_homo/ LIA/");
	system("mv homo_hete_hete/ LIA/");
	system("mv hete_homo_homo/ LIA/");
	system("mv hete_homo_hete/ LIA/");
	system("mv hete_hete_homo/ LIA/");
	system("mv hete_hete_hete/ LIA/");

	system("sysctl -w net.ipv4.tcp_congestion_control=olia");
	
	funcao();
	
	system("mv homo_homo_homo/ OLIA/");
	system("mv homo_homo_hete/ OLIA/");
	system("mv homo_hete_homo/ OLIA/");
	system("mv homo_hete_hete/ OLIA/");
	system("mv hete_homo_homo/ OLIA/");
	system("mv hete_homo_hete/ OLIA/");
	system("mv hete_hete_homo/ OLIA/");
	system("mv hete_hete_hete/ OLIA/");

	system("sysctl -w net.ipv4.tcp_congestion_control=balia");
	
	funcao();
	
	system("mv homo_homo_homo/ BALIA/");
	system("mv homo_homo_hete/ BALIA/");
	system("mv homo_hete_homo/ BALIA/");
	system("mv homo_hete_hete/ BALIA/");
	system("mv hete_homo_homo/ BALIA/");
	system("mv hete_homo_hete/ BALIA/");
	system("mv hete_hete_homo/ BALIA/");
	system("mv hete_hete_hete/ BALIA/");

	system("sysctl -w net.ipv4.tcp_congestion_control=wvegas");
	
	funcao();
	
	system("mv homo_homo_homo/ wVegas/");
	system("mv homo_homo_hete/ wVegas/");
	system("mv homo_hete_homo/ wVegas/");
	system("mv homo_hete_hete/ wVegas/");
	system("mv hete_homo_homo/ wVegas/");
	system("mv hete_homo_hete/ wVegas/");
	system("mv hete_hete_homo/ wVegas/");
	system("mv hete_hete_hete/ wVegas/");

	system("sh dados_tshark.sh");
	return 0;
}


