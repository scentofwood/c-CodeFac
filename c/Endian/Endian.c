#include <sys/utsname.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
    struct utsname uts;
    union {
        short s;
        char c[sizeof(short)];
    } un;
    un.s = 0x0102;

    if (uname(&uts) < 0) exit(1);

    printf("**********************************************************\n");
    printf(" sysname   [%s]\n machine   [%s]\n nodename  [%s]\n release   [%s]\n version   [%s]\n domainname[%s]\n\n ==> ", 
            uts.sysname, 
            uts.machine, 
            uts.nodename, 
            uts.release, 
            uts.version,
            uts.__domainname);
    if (sizeof(short) == 2) {
        if (un.c[0] == 1 && un.c[1] == 2)
            printf("BIG Endian\n");
        else if (un.c[0] == 2 && un.c[1] == 1)
            printf("LITTLE Endian\n");
        else
            printf("Unkown\n");
    }
    else {
        printf("sizeof(short) = %ld\n", sizeof(short));
    }
    printf("**********************************************************\n");

    exit(0);
}