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

int main(int argc, char argv[]){
    int fd[2];
    int ret , i;
    pid_t pid;

    ret = pipe(fd); //创建并打开管道 fd[0]读端  fd[1]写端 
    //create a pipe; success 成功返回0， 失败返回-1
    if(ret == -1){
        sys_err("pipe error");
    } 

    for (i=0; i<2; i++) {   //表达式i=2 出口， 仅限父进程使用 
        pid = fork();//创建子进程， 成功， 返回子进程id，；  失败返回-1
        if (pid == -1) { 
            sys_err("fork error");
        }
        if(pid == 0){ //子进程出口
            break;  
        }
    }

    if (i==2) { //父进程， 不参与管道使用
        close(fd[0]); //0 read   fd1 write
        close(fd[1]);
        
        //pid_t wait(int *status)
        //wait函数：	回收子进程退出资源， 阻塞回收任意一个。
        wait(NULL); //回收子进程
        wait(NULL);
    } else if ( i == 0) { // xiong 
        close(fd[0]); //close read fd0
        dup2(fd[1], STDOUT_FILENO); // out -> fd1 write  重定向stdout
        execlp("ls", "ls", NULL); // 
        sys_err("exclp ls error");
    } else if (i == 1) {
        close(fd[1]); // close write fd1
        dup2(fd[0], STDIN_FILENO); // in -> fd0 read    重定向stdin
        execlp("wc", "wc", "-l", NULL); 
        sys_err("exclp wc error");
    }
    return 0;
}