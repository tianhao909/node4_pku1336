#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int var = 100;      //全局变量

int main(void){
    pid_t pid;
    
    pid = fork();

    if(pid == -1){
        perror("fork error");
        exit(1);
    } else if(pid > 0){ //child pid 大于0 说明是父进程
        var = 288;
        printf("parent, var = %d\n", var);
        printf("I'am parent pid= %d, getppid = %d, mychild pid=%d\n", getpid(), getppid(), pid);
    } else if (pid == 0) { //共享文件描述符， 建立映射区。
        var = 200; 
        printf("parent, var = %d\n", var); //改的是改各自的， 不共享全局变量，读时共享，写时复制
        printf("I'am child pid= %d, getppid = %d, mychild pid=%d\n", getpid(), getppid(), pid);
    }

    printf("-------------finish------------\n");
    return 0;
}

