#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    pid_t pid;
    pid = fork();

    if(0 == pid){ //child id == 0
        while(1){
            printf("I am child, my parent pid = %d, my pid = %d \n", getppid(),getpid());
            sleep(1);
        }
    } else if (pid > 0) { // parent process
        printf("I am parent, my pid is = %d \n" , getpid());
        sleep(1);
        printf("------------parent going to die---------------\n");
    } else {
        perror("fork");
        return 1;
    }
    return 0;
}