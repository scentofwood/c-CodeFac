#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

int main(void)
{
    int msgid;
    struct msqid_ds buf;

    key_t key = 1234;
    // rw-r--r-- 권한으로 큐를 생성할 수도 있다.
    msgid = msgget(key, IPC_CREAT|0644);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }
    
    // kernel 데이터구조로부터 특정 msgid 큐관련 상태정보를 얻는다.
    /* 매뉴얼 - msgctl 중 IPC_STAT 설명
    Copy  information from the kernel data structure associated with
    msqid into the msqid_ds structure pointed to by buf.  The caller
    must have read permission on the message queue.
    */
    printf("= Queue INFORMATION = \n");
    msgctl(msgid, IPC_STAT, &buf);
    printf("* Current number of bytes in queue (nonstandard) : %ld\n", buf.__msg_cbytes);
    printf("* Current number of messages in queue            : %ld\n", buf.msg_qnum);
    printf("* Maximum number of bytes allowed in queue       : %ld\n", buf.msg_qbytes);
    printf("* PID of last msgsnd(2)                          : %d\n", buf.msg_lspid);
    printf("* PID of last msgrcv(2)                          : %d\n", buf.msg_lrpid);

    // 특정 msgid 큐를 삭제한다.
    /* 매뉴얼 - msgctl 중 IPC_RMID 설명
    Immediately  remove  the  message  queue,  awakening all waiting
    reader and writer processes (with an error return and errno  set
    to EIDRM).  The calling process must have appropriate privileges
    or its effective user ID must be either that of the  creator  or
    owner  of  the message queue.  The third argument to msgctl() is
    ignored in this case. 
    */
    printf("= Queue DELETE...");
    if (msgctl(msgid, IPC_RMID, 0) == 0) {
        printf("DONE SUCCESSFULLY!!\n");
    } else {
        printf("FAILED!!\n");
    }

    return 0;
}