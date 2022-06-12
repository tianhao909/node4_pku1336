#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    pid_t pid;
    pid = fork();
    pid_t wpid;
    int status;

    if(0 == pid){ 
         printf("---child, my parent=%d, my pid = %d, going to sleep 10s \n", getppid(), getpid());
         sleep(20);
         printf("--------child die-------------\n");
         return 73;
    } else if ( pid > 0) { 
        wpid = wait(&status);   //如果子进程为终止，父进程阻塞在这个函数上
        //pid_t wait(int *status)
        // 参数int *status：（传出） 回收进程的状态
        //返回值pid_t：成功： 回收进程的pid  ; 失败： -1， errno
        if(wpid == -1){
            perror("wait error");
            exit(1);
        }
        //获取子进程正常终止值： WIFEXITED(status) --》 为真 
        if(WIFEXITED(status)){  //为真， 说明子进程正常终止 
            //--》调用 WEXITSTATUS(status) --》 得到 子进程 退出值。
            printf("child exit with %d\n", WEXITSTATUS(status));
        }

        //获取导致子进程异常终止信号：
		//WIFSIGNALED(status) --》 为真 --》
        if(WIFSIGNALED(status)){ //为真，说明子进程是被信号终止
            //调用 WTERMSIG(status) --》 得到 导致子进程异常终止的信号编号。
            printf("child kill with signal %d\n", WTERMSIG(status));
        } 

        printf("-------------parent wait finish\n", wpid);
    } else {
            perror("fork");
            return 1;
    }
    return 0;   
}