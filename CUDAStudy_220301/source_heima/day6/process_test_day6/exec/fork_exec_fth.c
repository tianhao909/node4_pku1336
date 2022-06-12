#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    } else if (pid == 0){ //child process 
        //char *argv[] = {"ls", "-l", "-h", "NULL"};
        char * args[] = {"ls", "-l", "-h", "NULL"};
        execvp("ls", args);
        perror("exec error");
        exit(1);
    } else if (pid > 0) {
        printf("i am parent: %d\n", getpid());
    }
    return 0;

}