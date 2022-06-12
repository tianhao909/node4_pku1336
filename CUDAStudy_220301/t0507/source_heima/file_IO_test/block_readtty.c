#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
	char buf[10];
	int n;

	n = read(STDIN_FILENO, buf, 10);   // #define STDIN_FILENO 0   STDOUT_FILENO 1  STDERR_FILENO 2
	if(n < 0){ //读失败 退出
		perror("read STDIN_FILENO");
		exit(1);
	}
	write(STDOUT_FILENO, buf, n); //写到标准输出上
	
	return 0;
}
