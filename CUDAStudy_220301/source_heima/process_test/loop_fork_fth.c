#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[]) {

    int i;
    pid_t pid;

    for(i=0; i<5; i++){
        if(fork() == 0){
            break; //杀死子进程
        } 
        if (5 == i) {
            sleep(1);
            printf("I am parent \n");
        } else {
            sleep(1);
            printf("i am %dth child \n", i+1);
        }
    }

    // int i;
    // pid_t pid;
    // for(i =0; i<5; i++){
    //     if(fork()==0){
    //         break;
    //     }

    //     printf("I'am %dth child\n",i+1);
    // }


    // int i;
    // pid_t pid = fork();
    // pid_t pid2 = fork();
    // pid_t pid3 = fork();

    // //pid_t pid = fork();
    // for(i=0; i<5;i++){
    //     //pid_t pid = fork();
    //     if(pid == -1){
    //         perror("fork error");
    //         exit(1);
    //     } else if (pid == 0) {
    //         printf("---child is created, my child is %d, my pid=%d, parent-pid=%d \n",pid, getpid(), getppid());
    //     } else if (pid > 0) {
    //         printf("---parent process: my child is %d,  my pid=%d, parent-pid=%d\n",pid, getpid(), getppid() );
    //     }
    // }




    printf("===============end of file\n");

    return 0;
}

