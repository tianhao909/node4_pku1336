#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

void catch_child(int signo){
    pid_t wpid;

    wpid = wait(NULL);
    if(wpid == -1){
        sys_err("wait error");
    }
    printf("catch child id %d\n", wpid);
    return ;
}

int main(int argc, char *argv[]){
    pid_t pid;
    
    int i;
    for(i=0; i<15; i++){
        if( (pid=fork()) == 0){
            break;
        }   
    }

    if (15 == i) {//parent process
        //waitpid(NULL );
        struct sigaction act;  //父进程

        act.sa_handler = catch_child;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;

        sigaction(SIGCHLD, &act, NULL);

        printf("I'm parent, pid = %d\n", getpid());

        while(1);
    } else {
        printf("I'm child pid = %d\n", getpid());
    }

    return 0;
}