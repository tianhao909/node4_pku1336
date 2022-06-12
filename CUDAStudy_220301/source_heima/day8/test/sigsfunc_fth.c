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

void print_set(sigset_t *set){
    int i;
    for(i=1; i<32; i++) {
        //sigismember（const sigset_t *set，int signum); 
        //判断一个信号是否在集合中。 在--》1， 不在--》0
        if(sigismember(set, i)){
            putchar('1');
        } else {
            putchar('0');
        }
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    sigset_t set, oldset, pedset;  //sigset_t set;  自定义信号集。
    
    int ret = 0;

    sigemptyset(&set); //sigemptyset(sigset_t *set);	清空信号集
    sigaddset(&set, SIGINT); //sigaddset(sigset_t *set, int signum);	将一个信号添加到集合中
    sigaddset(&set, SIGQUIT);
    //int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
    //设置信号屏蔽字和解除屏蔽：
    //int how:	SIG_BLOCK:	设置阻塞
    //          SIG_UNBLOCK:	取消阻塞
    //          SIG_SETMASK:	用自定义set替换mask。
    //set：	自定义set
    //oldset：旧有的 mask。
    //kill -l
    ret = sigprocmask(SIG_BLOCK, &set, &oldset);//成功0 失败-1
    if(ret == -1){
        sys_err("sigprocmask error");
    }

    //查看未决信号集：
    //int sigpending(sigset_t *set);
    //set： 传出的 未决信号集。
    while(1){
        ret = sigpending(&pedset); //成功0 失败-1
        if(ret == -1){
            sys_err("sigpending error");
        }
        print_set(&pedset);
        sleep(1);
    }
    return 0;
}
