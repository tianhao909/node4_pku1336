#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>  
#include <string.h> 

//循环回收多个子进程
int main(int argc, char * argv[]) {
    int i;
    pid_t pid, wpid;

    for(i = 0; i<5; i++){
        pid = fork(); //pid = childpid  
        if(pid == 0){ //child process  子进程不fork  fork 
            break;
        }
    }    

    if (5 == i) { //parent fork 才可能等于 5
        //pid_t waitpid(pid_t pid, int *status, int options) 
        //参数： pid：指定回收某一个子进程pid
        //返回值： > 0 : 表成功回收的子进程 pid 
        //0 : 函数调用时， 参3 指定了WNOHANG， 并且，没有子进程结束。
        //-1: 失败。errno
        while( (wpid = waitpid(-1, NULL, WNOHANG) ) != -1 ){ //等于-1 则回收失败
            if( wpid > 0 ){ //wpid = waitpid返回值： > 0 : 表成功回收的子进程 pid 
                printf("wait child %d \n", wpid);
            } else if (wpid == 0) {  //waitpid 返回 0 : 函数调用时， 参3 指定了WNOHANG， 并且，没有子进程结束。
                sleep(1);
                continue;
            }
        }
    } else { //子进程， 从break跳出  //每个进程的i不一样， 五个子进程的i 0 1 2 3 4 父进程的i 5
        sleep(i);
        printf( "I'm %dth child, pid = %d\n", i,getpid() );
    }
    return 0;
}