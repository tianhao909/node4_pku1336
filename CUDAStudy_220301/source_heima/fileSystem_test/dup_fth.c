#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    int newfd = dup(fd); //文件描述符可以访问open打开的文件 复制版本 
    printf("newfd = %d\n", newfd);
    
    
    //write(newfd, "1234567", 7);
    
    return 0;
}