#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int i;
    pid_t pid, wpid, tmpid;
    
    for(i=0; i<5; i++){
        pid = fork();
        //if( fork()==0 ){ //循环期间，子进程不fork
        if( pid == 0 ){
            break;
        }
        if (2 == i) {
            tmpid = pid;
            printf("--------pid = %d \n", tmpid);
        }
    }
    if ( 5 == i ) { //父进程， 从表达式2跳出
        sleep(5);
        //waitpid函数：	指定某一个进程进行回收。可以设置非阻塞
        //pid_t waitpid(pid_t pid, int *status, int options)
        //pid_t pid：指定回收某一个子进程pid   > 0: 待回收的子进程pid   -1：任意子进程   0：同组的子进程。
        //int *status：（传出） 回收进程的状态。
        //int options：WNOHANG 指定回收方式为，非阻塞。

        //wpid = waitpid(-1, NULL, WNOHANG);
        //wpid = waitpid(pid, NULL, WNOHANG);
        wpid = waitpid(tmpid, NULL, 0);
        if( wpid == -1 ){
            perror("waitpid error");
            exit(1);
        }
        printf("I'm parent, wait a child finish: %d\n", wpid);
    } else {
        sleep(3);
        printf("I'm %dth child, my pid=%d, my parent id=%d \n", i+1, getpid(), getppid());
    }
}