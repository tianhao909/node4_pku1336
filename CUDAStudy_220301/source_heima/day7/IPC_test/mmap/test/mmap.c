#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

int main(int argc, char *argv[])
{
    char *p = NULL;
    int fd;

    fd = open("testmap", O_RDWR|O_CREAT|O_TRUNC, 0644);     // 创建文件用于创建映射区
    if (fd == -1)
        sys_err("open error");
/*
    lseek(fd, 10, SEEK_END);            // 两个函数等价于 ftruncate(fd, 10)函数
    write(fd, "\0", 1);
*/
    // int ftruncate(int fd, off_t length);  off_t文件偏移量， long， 32位整数
    //On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.
    ftruncate(fd, 20);                  // 需要借助写权限,才能够对文件进行拓展
    int len = lseek(fd, 0, SEEK_END); 
    //off_t lseek(int fd, off_t offset, int whence);
    //off_t fd：文件描述符  offset： 偏移量，就是将读写指针从whence指定位置向后偏移offset个单位
    //whence：起始偏移位置： SEEK_SET/SEEK_CUR/SEEK_END

    //void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
    //创建共享内存映射
    //void *addr： 	指定映射区的首地址。通常传NULL，表示让系统自动分配
    //size_t length：共享内存映射区的大小。（<= 文件的实际大小）
    //int prot：	共享内存映射区的读写属性。PROT_READ、PROT_WRITE、PROT_READ|PROT_WRITE
    //int flags：	标注共享内存的共享属性。MAP_SHARED、MAP_PRIVATE   flags里面的shared意思是修改会反映到磁盘上   private表示修改不反映到磁盘上
    //int fd:	用于创建共享内存映射区的那个文件的 文件描述符。
    //off_t offset：默认0，表示映射文件全部。偏移位置。需是 4k 的整数倍。
    //void *  成功：映射区的首地址。  失败：MAP_FAILED (void*(-1))， errno
    p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);  //char *p = NULL;
    if (p == MAP_FAILED) {
        sys_err("mmap error");
    }

    // 使用 p 对文件进行读写操作.
    strcpy(p, "hello mmap");            // 写操作

    printf("----%s\n", p);              // 读操作

    //int munmap(void *addr, size_t length);		释放映射区。
    //void *addr：mmap 的返回值
    //size_t length：大小
    int ret = munmap(p, len);           // 释放映射区
    if (ret == -1) {
        sys_err("munmap error");
    }

	return 0;
}
