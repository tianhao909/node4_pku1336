#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

void sig_cath(int signo){
    printf("catch you!! %d\n", signo);
    return ;
}

int main(int argc, char *argv[]){
    //typedef void (*sighandler_t)(int);
    //sighandler_t signal(int signum, sighandler_t handler);
    //第一个参数signum：指明了所要处理的信号类型，它可以取除了SIGKILL和SIGSTOP外的任何一种信号。
    //第二个参数handler：描述了与信号关联的动作，它可以取以下三种值： 
    signal(SIGINT, sig_cath);
    while(1);
    return 0;
}