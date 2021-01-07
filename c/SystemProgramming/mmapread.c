#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, const char *argv[]) {
    // 미리 link.txt 만든다. 내용은 아무거나.
    char *filepath = "link.txt";
    struct stat fileInfo;
    int fd;
    fd = open(filepath, O_RDONLY, (mode_t)0600);
    if (fd < 0) {
        printf("can't open file\n");
        exit(EXIT_FAILURE);
    }
    fstat(fd, &fileInfo);
    printf("File size is %ji\n", (intmax_t)fileInfo.st_size);
    
    char *map = mmap(0, fileInfo.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        close(fd);
        perror("Error mmapping the file");
        exit(EXIT_FAILURE);
    }

    // 물리적 디스크에 접근하는 것이 아니기에
    // 스케쥴링 없이 바로 메모리에 접근 ==> 그래서 빠르다!
    for (off_t i = 0; i < fileInfo.st_size; i++) {
        printf("Found character [%02x] [%c] at %ji\n", map[i], map[i], (intmax_t)i);
    }

    if (munmap(map, fileInfo.st_size) == -1) {
        close(fd);
        perror("Error un-mmapping the file");
        exit(EXIT_FAILURE);
    }
    close(fd);
    return 0;
}