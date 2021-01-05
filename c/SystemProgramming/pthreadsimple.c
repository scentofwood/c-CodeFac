#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*****************************************************************************
 * compile : gcc -pthread pthreadsimple.c -o pthreadsimple
*****************************************************************************/

void *thread_function_1(void *ptr) {
    char *message;
    message = (char *)ptr;
    printf("%s start\n", message);
    sleep(3);
    printf("%s end\n", message);
    pthread_exit((void *)100);  // 100은 그냥 임의값임
}
void *thread_function_2(void *ptr) {
    char *message;
    message = (char *)ptr;
    printf("%s start\n", message);
    sleep(3);
    printf("%s end\n", message);
}

int main() {
    pthread_t thread1, thread2;
    const char *message1 = "Thread 1";
    const char *message2 = "Thread 2";
    int ret, status;

    printf("TEST 1 (pthread_join) ==================================\n");

    // 쓰레드 생성
    ret = pthread_create(&thread1, NULL, thread_function_1, (void *)message1);
    printf("thread1 %d\n", ret);
    if (ret == 0) {
        printf("pthread_create returns %d\n", ret);
    } else {
        printf("pthread_create returns error: %d\n", ret);
        exit(1);
    }
    // 쓰레드 조인
    // 1. 프로세스는 쓰레드가 끝날 때까지 기다림
    // 2. 쓰레드는 끝나자마자 free 됨
    pthread_join(thread1, (void **)&status);
    printf("쓰레드 끝날 때 기다린 후 출력. 쓰레드 결과상태값 [%d] \n", status);

    printf("TEST 2 (pthread_join) ==================================\n");
    
    // 쓰레드 생성
    ret = pthread_create(&thread2, NULL, thread_function_2, (void *)message2);
    printf("thread2 %d\n", ret);
    if (ret == 0) {
        printf("pthread_create returns %d\n", ret);
    } else {
        printf("pthread_create returns error: %d\n", ret);
        exit(1);
    }
    // 쓰레드 디태치
    // 1. 프로세스는 쓰레드가 끝날 때까지 기다리지 않음
    // 2. 쓰레드는 끝나자마자 free 됨
    pthread_detach(thread2);
    printf("쓰레드 끝날 때 기다리지 않고 출력. 당연히 쓰레드 결과상태값 모름 \n");

    sleep(10);
 
    return 0;
}