/*
  명령어 : gcc TcpClient.c -o TcpClient
  실행문 : ./TcpClient 127.0.0.1 7000
*/
#include <stdio.h>
#include <stdlib.h>     // _sleep 함수가 선언된 헤더파일
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>     // 리눅스에서 usleep 함수가 선언된 헤더파일

#define MAXLINE 1024 //buf 크기
#define TOTALFORK 5 //클라이언트 수

void createClient(char *port, char *serverIP);

int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf("Use %s ip_addr port\n", argv[0]);
		exit(0);
	}

	pid_t pids[TOTALFORK]; //client fork
	int runProcess = 0;
	
	while(runProcess < TOTALFORK) {

		sleep(1);

		pids[runProcess] = fork();

		if(pids[runProcess] < 0) {
			return -1;
		}
		
		if(pids[runProcess] == 0) {
			createClient(argv[2], argv[1]);
			exit(0);
		} else { //부모 프로세스
			printf("parent %ld, child %ld\n", (long)getpid(), (long)pids[runProcess]);
		}
		runProcess++;
	}

 	// 20초 후에 끝내자
    sleep(20);
    printf("--- END ---\n");

	return 0;
}

void createClient(char *port, char *serverIP) {
	struct sockaddr_in servaddr;
	int strlen = sizeof(servaddr);
	int sockfd, buf, cNum;//cNum 연결 번호

    // 5초만 쉬었다 하자
    sleep(5);

	if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket fail");
		exit(0);
	}

	memset(&servaddr, 0, strlen);
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, serverIP, &servaddr.sin_addr);
	servaddr.sin_port = htons(atoi(port));

	if(connect(sockfd, (struct sockaddr *)&servaddr, strlen) < 0) {
		perror("connect fail");
		exit(0);
	}
	
	srand((unsigned)time(NULL));
	buf = rand() % 100 + 1; //rand 값 생성
	write(sockfd, &buf, 4); //server로 전송
	printf("Client value : %d \t  and  ", buf);
	read(sockfd, &buf, 4); //server에서 받아 옴
	printf("Server sum result : %d\n", buf);
	close(sockfd);
}