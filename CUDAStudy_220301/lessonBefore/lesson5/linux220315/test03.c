#include <unistd.h>
#include <stdio.h>
int main(void) {
    int i = 0;
    printf("i son/pa ppid pid fpid\n");
    // ppid is the pid of the parent process of current process
    // pid is the pid of the current process
    // fpid is hte value of the current process which fork returned
    for (i = 0; i<2; i++) {
        pid_t fpid = fork();
        if (fpid == 0) {
            printf("%d child %4d %4d %4d\n",i, getppid(), getpid(), fpid);
        } else {

            printf("%d parent %4d %4d %4d\n",i, getppid(), getpid(), fpid);
        } 
    }
    return 0;
}