#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define N 5

void sys_err(const char *str){
    perror(str);
    exit(1);
}

int main(int argc, char *argv[]){
    pid_t pid = fork();
    
    if(pid > 0){ //parent process
        while(1){
            printf("parent, pid=%d\n", getpid());
            sleep(1);
        }
    } else if (pid == 0) { //child process
        //
        printf("child pid=%d, ppid=%d\n", getpid(), getppid());
        sleep(10);
        kill(0, SIGKILL);
        //while(1);
        //kill(getppid(), SIGCHLD);
        //int kill(pid_t pid, int sig);
        //kill(getpid(), SIGKILL);
        //kill(getppid(), SIGKILL);
    }
    return 0;
}