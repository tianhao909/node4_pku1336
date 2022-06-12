/*
 * 后执行,尝试读取另外一个进程写入文件的内容
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    char buf[1024];
    char *str = "--------------test2 write success--------\n";
    int ret;

    sleep(2); //睡眠2秒，保证test1将数据写入test.txt 文件
    
    int fd = open("test.txt", O_RDWR);

    //尝试读取test.txt文件中test1写入的数据
    ret = read(fd, buf, sizeof(buf));

    //将读到的数据打印至屏幕
    write(STDOUT_FILENO, buf, ret);

    //写入数据到文件test.txt中， 未修改读写位置
    write(fd, str, strlen(str));

    printf("test2 read/write finish\n");

    close(fd);

    return 0;
}