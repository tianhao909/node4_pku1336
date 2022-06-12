#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[]){
    int fd1 = open(argv[1], O_RDWR);
    printf("fd1=%d\n", fd1);

    int newfd = fcntl(fd1, F_DUPFD, 0); //0被占用 用最小的
    printf("newfd = %d\n", newfd);

    int newfd2 = fcntl(fd1, F_DUPFD, 7); //7被占用 返回大于等于7的file descriptor
    printf("newfd2 = %d\n", newfd2);

    int ret = write(newfd2, "YYYYYYYYYYYYYY", 7);
    printf("ret=%d\n", ret);
    
    return 0;
}