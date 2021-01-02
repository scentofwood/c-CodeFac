#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MSGSIZE 255

char* msg = "Hello Child Process!!";

int main() 
{
    char buf[255];
    int fd[2], pid, nbytes;

    if (pipe(fd) < 0)
        exit(1);
    
    pid = fork();

    switch (pid) {
    case -1:
        perror("[PRNT] fork() is failed\n");
        break;
    case 0:
        // 자식프로세스
        printf("[CHLD] This is Child process. Child PID[%d]\n", getpid());
        nbytes = read(fd[0], buf, MSGSIZE);
        printf("[CHLD] reads %d bytes. [%s]\n", nbytes, buf);
        break;
    default:
        // 부모프로세스
        printf("[PRNT] This is Parent process. Parent PID[%d] Child PID[%d]\n", getpid(), pid);
        
        write(fd[1], msg, strlen(msg) > MSGSIZE ? MSGSIZE: strlen(msg));
        break;
    }

    return 0;
}