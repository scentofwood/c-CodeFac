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
        exit(1);
    }
    
    // msg.type 은 송신측에서 세팅한 msg.type 과 관련이 있다.
    // 0       : 송신측의 msg.type 상관없이 모든 타입을 큐에서서 순서대로 받는다.
    // 그외숫자 : 송신측의 msg.type 과 동인한 큐만 순서대로 받는다.
    msg.type = 0;
    // msgflag
    // 0 (WAIT)   : Block mode     => 통상 수신측은 WAIT
    // IPC_NOWAIT : Non-Block mode => 또는 NOWAIT 로 읽고 없으면 뺑뺑이이 다시 읽고..
    msgflag = 0;
    len = msgrcv(msgid, &msg, MSGSIZE, msg.type, msgflag);
    printf("Received Message is [%d] %s\n", len, msg.text);

    return 0;
}