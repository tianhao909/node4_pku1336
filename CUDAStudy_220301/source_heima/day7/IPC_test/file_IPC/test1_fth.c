/*
 * 先执行,将数据写入文件test.txt
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int main(void)
{
    char buf[1024];
    char *str = "-------------success-----------------\n";
    int ret;

    int fd = open("test.txt", O_RDWR | O_TRUNC | O_CREAT, 0664);
    //O_TRUNC 如果文件存在 ，  则长度被截为0， 属性不变

    //直接卡开文件写入数据
    write(fd, str, strlen(str));
    printf("test1 write into test.txt finish\n");

    sleep(N);
    // 下列是较特别的使用方式:
    // 1) 欲将读写位置移到文件开头时:
    // lseek（int fildes,0,SEEK_SET）；
    // 2) 欲将读写位置移到文件尾时:
    // lseek（int fildes，0,SEEK_END）；
    // 3) 想要取得目前文件位置时:
    // lseek（int fildes，0,SEEK_CUR）；
    lseek(fd, 0, SEEK_SET);
    ret = read(fd, buf, sizeof(buf));
    ret = write(STDOUT_FILENO, buf , ret);
    
    if (ret == -1) {
        perror("write second error");
        exit(1);
    }

    close(fd);

}