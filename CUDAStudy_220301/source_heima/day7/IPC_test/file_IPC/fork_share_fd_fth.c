/* 
 *父子进程共享打开的文件描述符------使用文件完成进程间通信.
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(void)
{
    int fd1, fd2; 
    pid_t pid;
    char buf[1024];   
    char *str = "---------test for shared fd in parent child process-----\n";

    pid = fork();
    if (pid < 0) { 
        perror("fork error");
        exit(1);
    } else if ( pid == 0) {
        fd1 = open("test.txt", O_RDWR); //open(), openat(), and creat() return the new file descriptor, or  -1  if  an  error occurred (in which case, errno is set appropriately).
        if (fd1 < 0) {
            perror("open error");
            exit(1);
        }
        sleep(3);
        write(fd1, str, strlen(str));
        printf("child wrote over ...\n");
    } else { //parent process
        fd2 = open("test.txt", O_RDWR);
        if (fd2 < 0) {
            perror("open error");
            exit(1);
        }

        int len = read(fd2, buf, sizeof(buf));
        printf("------parent read len = %d\n", len);
        len = write(STDOUT_FILENO, buf, len);  //写到 stdout， 输出到屏幕上 
        printf("------parent write len = %d\n", len);

        wait(NULL);
    }

}