#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char *argv[]) {
    // 미리 link.txt 만든다. 내용은 아무거나.
    char *filepath = "link.txt";
    char *update = "HELLO MMAP!";
    struct stat fileInfo;
    int fd;
    fd = open(filepath, O_RDWR, (mode_t)0600);
    if (fd < 0) {
        printf("can't open file for writing\n");
        exit(EXIT_FAILURE);
    }
    fstat(fd, &fileInfo);
    printf("File size is %ji\n", (intmax_t)fileInfo.st_size);
    
    char *map = mmap(0, fileInfo.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        close(fd);
        perror("Error mmapping the file");
        exit(EXIT_FAILURE);
    }

    // 물리적 디스크에 접근하는 것이 아니기에
    // 스케쥴링 없이 바로 메모리에 접근 ==> 그래서 빠르다!
    printf("%ld\n", strlen(update));
    for (size_t i = 0; i < strlen(update); i++) {
        printf("Writing character [%02x] [%c] at %zu\n", update[i], update[i], i);
        map[i] = update[i];
    }

    if (msync(map, fileInfo.st_size, MS_SYNC) == -1) {
        perror("Could not sync the file to disk");
    }

    if (munmap(map, fileInfo.st_size) == -1) {
        close(fd);
        perror("Error un-mmapping the file");
        exit(EXIT_FAILURE);
    }
    close(fd);
    return 0;
}