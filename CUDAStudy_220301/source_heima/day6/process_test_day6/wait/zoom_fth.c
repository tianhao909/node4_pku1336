#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    pid_t pid;
    pid = fork();

    if(0 == pid){
         printf("---child, my parent=%d, my pid = %d, going to sleep 10s \n", getppid(), getpid());
         sleep(10);
         printf("--------child die-------------\n");
    } else if ( pid > 0) {
        while(1){
            printf("I am parent, my pid = %d, myson pid = %d \n", getpid(), pid);
            sleep(1);
        } 
    } else {
            perror("fork");
            return 1;
    }
    
}