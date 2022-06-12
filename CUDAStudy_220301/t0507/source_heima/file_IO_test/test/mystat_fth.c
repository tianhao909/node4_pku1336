#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    struct stat sbuf; //传出参数， 有效，但没有实际意义， 
    //int stat(const char *pathname, struct stat *statbuf);
    //int ret = stat(argv[1], &sbuf);
    int ret = lstat(argv[1], &sbuf);
    if (ret == -1) { //-1  失败   
        perror("stat error");
        exit(1);
    }
    //off_t     st_size;        /* Total size, in bytes */
    printf("file size:%ld\n", sbuf.st_size); 

    if(S_ISREG(sbuf.st_mode)) {
        printf("It's a regular\n");
    } else if (S_ISDIR(sbuf.st_mode)) {
        printf("It's a dir\n");
    } else if (S_ISFIFO(sbuf.st_mode)) {
        printf("It's a pipe\n");
    } else if (S_ISLNK(sbuf.st_mode)) {
        printf("it's a sym link\n");
    }

    return 0;
}