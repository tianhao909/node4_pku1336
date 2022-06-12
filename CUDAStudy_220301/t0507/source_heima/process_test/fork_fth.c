#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[]) {
    //pid_t pid = fork();
    printf("before fork-1-\n");     // 在fork之前打印,父进程执行,只执行一次
    printf("before fork-2-\n");
    printf("before fork-3-\n");
    printf("before fork-4-\n");

    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    } else if (pid == 0) {
        printf("---child is created, my child is %d, my pid=%d, parent-pid=%d \n",pid, getpid(), getppid());
    } else if (pid > 0) {
        printf("---parent process: my child is %d,  my pid=%d, parent-pid=%d\n",pid, getpid(), getppid() );
    }

    printf("===============end of file\n");

    return 0;
}

