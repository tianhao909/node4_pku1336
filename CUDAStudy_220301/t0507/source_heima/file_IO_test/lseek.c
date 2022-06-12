#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int fd, n;
	char msg[] = "It's a test for lseek\n"; //字符数组 
	char ch;

	fd = open("lseek.txt", O_RDWR|O_CREAT, 0644); //读写方式打开 不存在就创建 读写 读读
	if(fd < 0){
		perror("open lseek.txt error");
		exit(1);
	}

	write(fd, msg, strlen(msg));    //使用fd对打开的文件进行写操作，问价读写位置位于文件结尾处。
	//写  把 msg 写到fd对应的文件里面 
	lseek(fd, 0, SEEK_SET);         //修改文件读写指针位置，位于文件开头。 注释该行会怎样呢？

	while((n = read(fd, &ch, 1))){ //设备文件 网络文件才需要考虑阻塞 非阻塞
		if(n < 0){
			perror("read error");
			exit(1);
		}
		write(STDOUT_FILENO, &ch, n);   //将文件内容按字节读出，写出到屏幕
		//一次读一个字节 ， 
	}

	close(fd);

	return 0;
}
