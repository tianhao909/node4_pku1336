#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>


void sys_err(const char *str){
    perror(str);
    exit(1);
}


int main (int argc, char *argv[]) {
    int fd[2]; // 0 read 1 write
    int ret ; 
    pid_t pid;


    ret = pipe(fd); // 父进程先创建一个管道， 持有管道的读端和写端
    //create a pipe; success 成功返回0， 失败返回-1

    if (ret == -1) {
        sys_err("pipe error");
    }

    pid = fork(); //子进程同样持有管道的读和写端
    //创建子进程， 成功， 返回子进程id，；  失败返回-1
    if (pid == -1) {
        sys_err("fork error");
    }

    else if (pid > 0) {  //父进程 读0，  关闭写端fd1
        close(fd[1]); //关闭写端
        dup2(fd[0], STDIN_FILENO); //重定向stdin到管道的读端 fd0
        //int dup2(int oldfd, int newfd);
        execlp("wc", "wc", "-l", NULL); //执行wc -l 程序
        sys_err("execlp wc error");
    }

    else if (pid == 0) {
        close(fd[0]); //子进程 关闭 读端
        dup2(fd[1], STDOUT_FILENO);//重定向 stdout 到 管道写端
        execlp("ls", "ls", NULL); //子进程执行ls命令
        sys_err("exclp is error");
    }

    return 0;
}