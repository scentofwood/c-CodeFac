#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#define MSGSIZE 255

typedef struct msgbuf {
    long type;
    char text[MSGSIZE];
} MsgBuf;

int main(void) 
{
    int msgid, len, msgflag;
    MsgBuf msg;
    key_t key = 1234;
    // rw-r--r-- 권한으로 큐를 생성할 수도 있다.
    msgid = msgget(key, IPC_CREAT|0644);
    if (msgid == -1) {
        perror("msgget");
        exit(1);s
    }
    msg.type = 1;
    strcpy(msg.text, "Hello Message Queue!!\n");
    len = strlen(msg.text) > MSGSIZE ? MSGSIZE : strlen(msg.text);
    // msgflag
    // 0 (WAIT)   : Block mode
    // IPC_NOWAIT : Non-Block mode => 통상 송신측은 NOWAIT
    msgflag = IPC_NOWAIT;
    if (msgsnd(msgid, (void *)&msg, len, msgflag) == -1) {
        perror("msgsnd");
        exit(1);
    }

    return 0;
}