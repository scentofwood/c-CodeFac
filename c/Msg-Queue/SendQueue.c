/*************************************************************************
 * �� ���α׷��� ���������� ������ �� �ִ�.
 * �����쿡�� MinGW�� �̿��� �����Ϸ��� ���̶�� ������ �Ұ����ϴ�.
 * �ֳ��ϸ� �����쿡���� �޸� ������ �Ϸ��� Win32�� ����ϱ⿡..
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
    //�޽��� �����ϴ� ������������ ù ��° ����� �޽��� �����̾�� ��
    long type;
    char data[BUFF_SIZE];
} msg_data = {1, "C Programming ���� �޽���ť ����"};

int msqid;

int main(void)
{
    /* 1234 Ű�� ���� �޽��� ť�� �����ϰ� �޽��� ť �ĺ����� �������� ��ȯ.
       ���� 1234 Ű�� �޽��� ť�� ������ �޽��� ť�� �����Ͽ� �ĺ��ڸ� ��ȯ */
    if (-1 == msqid = msgget((key_t)1234, IPC_CREAT | 0666))
    {
        perror("msgget() ����");
        exit(1);
    }
    printf("msgget() ����\n");
    
    // msg_data �޽����� msqid �޽��� ť�� ����
    // if (-1 == msgsnd(msqid, &msg_data, strlen(msg_data.data), 0))
    if (-1 == msgsnd(msqid, &msg_data, sizeof(msg_data) - sizeof(long), 0))
    {
        perror("msgsnd() ����");
        exit(1);
    }
    printf("msgsnd() ����\n");
    
    // SIGINT �ñ׳� ������ signalHandler �����ϵ��� ����
    signal(SIGINT, signalHandler);
    pause();
}

void signalHandler(int signo)
{
    if (-1 == msgctl(msqid, IPC_RMID, 0))
    { // msqid �޽��� ť ����
        perror("msgctl() ����");
        exit(1);
    }
    printf("msgctl() ����\n");
    exit(0);
}
