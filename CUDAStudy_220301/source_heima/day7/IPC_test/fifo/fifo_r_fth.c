#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void sys_err(char *str)
{
    perror(str);
    exit(1);
}

int main(int argc, char *argv[])
{
    int fd, len;
    char buf[4096];
    
    if(argc < 2){
        printf("Enter list this: ./a.out fifoname\n");
        return -1;
    }

    fd = open(argv[1],O_WRONLY); // open pipe file  ; argv[0] argv[1]
    if(fd < 0){
        sys_err("open");
    }
    while(1){
        len = read(fd, buf, sizeof(buf)); // read data from pipe read fd
        write(STDOUT_FILENO, buf, len);
        sleep(1);  //多个读端时， 应增加睡眠秒数， 放大效果 
    }
    close(fd);
    return 0;
    
}