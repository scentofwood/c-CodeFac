/*************************************************************************
 * 이 프로그램은 리눅스에서 실행할 수 있다.
 * 윈도우에서 MinGW를 이용해 실행하려는 것이라면 컴파일 불가능하다.
 * 왜냐하면 윈도우에서는 메모리 공유를 하려면 Win32를 써야하기에..
*************************************************************************/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

#define BUFF_SIZE 1024

void signalHandler(int signo);

struct
{
    //메시지 저장하는 데이터형으로 첫 번째 멤버는 메시지 형식이어야 함
    long type;
    char data[BUFF_SIZE];
} msg_data = {1, "C Programming 으로 메시지큐 연습"};

int msqid;

int main(void)
{
    /* 1234 키를 갖는 메시지 큐를 생성하고 메시지 큐 식별자인 정수값을 반환.
       만약 1234 키의 메시지 큐가 있으면 메시지 큐에 접근하여 식별자를 반환 */
    if (-1 == msqid = msgget((key_t)1234, IPC_CREAT | 0666))
    {
        perror("msgget() 실패");
        exit(1);
    }
    printf("msgget() 성공\n");
    
    // msg_data 메시지를 msqid 메시지 큐에 전송
    // if (-1 == msgsnd(msqid, &msg_data, strlen(msg_data.data), 0))
    if (-1 == msgsnd(msqid, &msg_data, sizeof(msg_data) - sizeof(long), 0))
    {
        perror("msgsnd() 실패");
        exit(1);
    }
    printf("msgsnd() 성공\n");
    
    // SIGINT 시그널 받으면 signalHandler 실행하도록 설정
    signal(SIGINT, signalHandler);
    pause();
}

void signalHandler(int signo)
{
    if (-1 == msgctl(msqid, IPC_RMID, 0))
    { // msqid 메시지 큐 삭제
        perror("msgctl() 실패");
        exit(1);
    }
    printf("msgctl() 성공\n");
    exit(0);
}
