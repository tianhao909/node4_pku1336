#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define N 14

int main(int argc, char *argv[]) {
    int fd, fd_out;
    int n;
    char buf[N];

    fd = open("dict.txt", O_RDONLY);
    if(fd < 0) {
        perror("dict.txt", O_RDONLY);
        if(fd < 0) {
            perror("open dict.txt error");
            exit(1);
        }

        fd_out = open("dict.cp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(fd < 0) {
            perror("open dict.cp error");
            exit(1);
        }
        
    }
}