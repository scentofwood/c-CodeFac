#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void signal_handler (int signo) {
    printf("Catch SIGINT!, but no stop\n");
}

int main(void) {
    // 테스트방법
    // 우선 signalloop 실행하고
    // ps -ef | grep signalloop => pid 알 수 있음
    // kill -SIGINT [pid]
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        printf("Can't catch SIGINT!\n");
        exit(1);
    }

    for (;;)
        pause();

    return 0;
}