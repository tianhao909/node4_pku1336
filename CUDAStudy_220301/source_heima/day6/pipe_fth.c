#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void sys_err(const char *str){
    perror(str);
    exit(1);
    pid_t pid;

  
}

int main (int argc, char *argv[]) {
    int ret;
    int fd[2]; 
    pid_t pid;

    char *str = "hello pipe\n";
    char buf[1024];

    ret = pipe(fd); //创建并打开管道 fd[0]读端  fd[1]写端  
    if (ret == -1) {
        sys_err("pipe error");
    }
    pid = fork();
    if(pid >0){ //parent process
        close(fd[0]); //关闭读端
        sleep(3);
        write(fd[1], str, strlen(str)); // 写入写端
        //sleep(3);
        close(fd[1]);
    } else if (pid == 0){ //child process
        close(fd[1]); //子进程关闭写端
        ret = read(fd[0], buf, sizeof(buf)); //从读端读
        printf("child read ret = %d\n", ret );
        write(STDERR_FILENO,buf, ret);
        close(fd[0]);
    }
}