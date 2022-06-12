#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>

struct student {
    int id;
    char name[256];
    int age;
};

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

int main(int argc, char *argv[])
{
    int fd;
    //struct  student stu = {1, "xiaoming", 18};
    struct student *p; //结构体指针 p 接收 mmap的返回值
    struct  student stu;

    //fd = open("test_map", O_RDWR|O_CREAT|O_TRUNC, 0664);
    fd = open("test_map", O_RDONLY);
    if(fd==-1){
        sys_err("open error");
    }

    //ftruncate(fd, sizeof(stu)); //创建一个结构体studentd stu大小的共享内存映射区
    //p = mmap(NULL, sizeof(stu), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    p = mmap(NULL, sizeof(stu), PROT_READ, MAP_SHARED, fd,0);
    if (p == MAP_FAILED) {
        sys_err("mmap error");
    }
    //void *memcpy(void *dest, const void *src, size_t n);
    // The memcpy() function copies n bytes from memory area src to memory area dest.  The
    //    memory areas must not overlap.  Use memmove(3) if the memory areas do overlap.
    close(fd);
    while(1){
        printf("id=%d, name=%s,age=%d\n",p->id, p->name,p->age);//从共享内存p中读东西
        //memcpy(p,&stu,sizeof(stu));  //往共享内存p里面东西
        //stu.id++;
        usleep(10000);
        //sleep(1);
    }
    munmap(p , sizeof(stu));
    return 0;


    
}