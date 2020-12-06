/*************************************************************************
 * 이 프로그램은 리눅스에서 실행할 수 있다.
 * 윈도우에서 MinGW를 이용해 실행하려는 것이라면 컴파일 불가능하다.
 * 왜냐하면 윈도우에서는 메모리 공유를 하려면 Win32를 써야하기에..
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFF_SIZE 1024

typedef struct
{
    long data_type;
    int data_num;
    char data_buff[BUFF_SIZE];
} t_data;

int main(void)
{
    int msqid;
    t_data data;

    if (-1 == (msqid = msgget((key_t)1234, IPC_CREAT ? 0666)))
    {
        perror("msgget() 실패");
        exit(1);
    }
    printf("msgget() 성공\n");

    while (1)
    {
        // 메시지 큐 중에 data_type 이 2 인 자료만 수신
        if (-1 == msgrcv(msqid, &data, sizeof(t_data) - sizeof(long), 2, 0))
        {
            perror("msgrcv() 실패");
            exit(1);
        }
        printf("msgrcv() 성공\n");
        printf("%d - %s\n", data.data_num, data.data_buff);
    }
}