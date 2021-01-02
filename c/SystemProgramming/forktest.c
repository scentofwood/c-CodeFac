#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    pid_t child;
    int status;
    printf("[PRNT] Before fork() call\n");
    pid = fork();

    switch (pid) {
    case -1:
        perror("[PRNT] fork() is failed\n");
        break;
    case 0:
        // 자식프로세스
        printf("[CHLD] This is Child process. PID[%d] Real-PID[%d] PPID[%d]\n", pid, getpid(), getppid());
        for (int c = 0; c < 1000000; c++)
        {
            ;
        }
        execl("/bin/ls", "ls", "-al", NULL);
        perror("[CHLD] execl() is failed\n");
        break;
    default:
        // 부모프로세스
        printf("[PRNT] This is Parent process. PID[%d] Real-PID[%d] PPID[%d]\n", pid, getpid(), getppid());
        printf("[PRNT] Parent's waiting starts\n");
        // 자식프로세스가 exit 되면 SIGCHLD 시그널에 의해 아래 wait 함수에 응답이 온다.
        child = wait(&status);
        printf("[PRNT] Parent's waiting is over. Child is [%d] status[%d]\n", child, status);
    }

    for (int i = 0; i < 2000000000; i++)
    {
         ;
    }

    if (pid == 0)
    {
        // 이 라인은 실행되지 않을 것이다.
        // 왜냐하면 execl 에 의해서 process 4GB 중 User Space인 3GB 영역은 모두 ls 프로그램으로 덮어씌어졌기 때문에
        // execl 이하단의 로직은 사실 아무 의미 없다.
        printf("[CHLD] Child process is over\n");
    }
    else if (pid > 0) 
    {
        printf("[PRNT] Parent process is over\n");
    }

    return 0;
}
