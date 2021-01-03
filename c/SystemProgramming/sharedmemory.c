#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
//#include <sys/types.h>

int main(void) {
    int shmid, pid, child;
    int status;
    char *shmaddr_parent, *shmaddr_child;
    
    // 공유메모리 생성
    // 참고로 크기는 PAGE_SIZE 의 곱만큼 커짐.. 따라서 20바이트는 4K바이트로 증가할 듯. 맞나?
    // /proc/sys/kernel/shmmni => 4096B => 4KB
    shmid = shmget((key_t)1234, 20, IPC_CREAT|0644);
    if (shmid == -1) {
        perror("shmget() error\n");
        exit(1);
    }

    pid = fork();

    switch (pid) {
    case -1:
        perror("[PRNT] fork() is failed\n");
        break;
    case 0:
        // 자식프로세스
        printf("[CHLD] This is Child process. PID[%d] Real-PID[%d] PPID[%d]\n", pid, getpid(), getppid());
        
        // 공유메모리 연결
        // shmflg : 공유메모리의 읽기/쓰기 권한 (0 이면 읽기/쓰기 가능, SHM_RDONLY 이면 읽기만 가능)
        // 리턴값 : 성공시 연결된 공유메모리의 시작 주소를 리턴
        /*
        shmat()  attaches  the  System V  shared  memory segment identified by shmid to the address
        space of the calling process.  The attaching address is specified by shmaddr  with  one  of
        the following criteria:

        *  If  shmaddr  is NULL, the system chooses a suitable (unused) page-aligned address to at‐
        tach the segment.

        *  If shmaddr isn't NULL and SHM_RND is specified in shmflg, the attach occurs at  the  ad‐
        dress equal to shmaddr rounded down to the nearest multiple of SHMLBA.

        *  Otherwise, shmaddr must be a page-aligned address at which the attach occurs.
        */
        shmaddr_child = (char *)shmat(shmid, (char *)NULL, 0);
        strcpy((char *)shmaddr_child, "Hello Parent!");

        // 공유메모리 해제
        shmdt((char *)shmaddr_child);
        break;
    default:
        // 부모프로세스
        printf("[PRNT] This is Parent process. PID[%d] Real-PID[%d] PPID[%d]\n", pid, getpid(), getppid());
        printf("[PRNT] Parent's waiting starts\n");
        // 자식프로세스가 exit 되면 SIGCHLD 시그널에 의해 아래 wait 함수에 응답이 온다.
        child = wait(&status);
        printf("[PRNT] Parent's waiting is over. Child is [%d] status[%d]\n", child, status);

        // 공유메모리 연결
        // shmflg : 공유메모리의 읽기/쓰기 권한 (0 이면 읽기/쓰기 가능, SHM_RDONLY 이면 읽기만 가능)
        // 리턴값 : 성공시 연결된 공유메모리의 시작 주소를 리턴
        shmaddr_parent = (char *)shmat(shmid, (char *)NULL, 0);
        printf("[PRNT] Received from CHILD [%s]\n", shmaddr_parent);

        // 공유메모리 해제
        shmdt((char *)shmaddr_parent);

        for (int i = 0; i < 2000000000; i++)
        {
            ;
        }

        // 특정 msgid 큐를 삭제한다.
        /* 매뉴얼 - shmctl 중 IPC_RMID 설명
        Mark the segment to be destroyed.  The segment will  actually
        be  destroyed  only after the last process detaches it (i.e.,
        when  the  shm_nattch  member  of  the  associated  structure
        shmid_ds  is  zero).  The caller must be the owner or creator
        of the segment,  or  be  privileged.   The  buf  argument  is
        ignored.

        If  a segment has been marked for destruction, then the (non‐
        standard) SHM_DEST flag of the  shm_perm.mode  field  in  the
        associated data structure retrieved by IPC_STAT will be set.

        The   caller   must  ensure  that  a  segment  is  eventually
        destroyed; otherwise its pages  that  were  faulted  in  will
        remain in memory or swap.
        */
        shmctl(shmid, IPC_RMID, 0);
        printf("[PRNT] SharedMemory DELETED\n");
 
        break;
    }

    return 0;
}