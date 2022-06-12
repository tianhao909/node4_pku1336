#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void myfunc(int signo){
    printf("hello world\n");
}

int main(void){
    struct itimerval it, oldit;

    //C 库函数 void (*signal(int sig, void (*func)(int)))(int) 
    //sighandler_t signal(int signum, sighandler_t handler);
    //设置一个函数来处理信号，即带有 sig 参数的信号处理程序。
    signal(SIGALRM, myfunc); //注册SIGALRM信号的捕捉处理函数

    it.it_value.tv_sec = 2; //it_value;  ---> 第一次定时秒数  time_t      tv_sec;     
    it.it_value.tv_usec = 0; //suseconds_t tv_usec; 
    
    it.it_interval.tv_sec = 5;//it_interval;---> 周期定时秒数 time_t      tv_sec;         /* seconds */
    it.it_interval.tv_usec = 0; //suseconds_t tv_usec;        /* microseconds */

    //int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);
    //which：	ITIMER_REAL： 采用自然计时。 ——> SIGALRM
    //          ITIMER_VIRTUAL: 采用用户空间计时  ---> SIGVTALRM
    //          ITIMER_PROF: 采用内核+用户空间计时 ---> SIGPROF
    //const struct itimerval *new_value：定时秒数

    if(setitimer(ITIMER_REAL, &it, &oldit) == -1){ //成功： 0 失败： -1 errno
        perror("setitimer error");
        return -1;
    }


}