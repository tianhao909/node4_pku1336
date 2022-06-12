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
    //void perror(const char *s);
    // The  perror()  function  produces  a  message on standard error describing the last
    //    error encountered during a call to a system or library function.

    //    First (if s is not NULL and *s is not a null byte ('\0')), the argument string s is
    //    printed,  followed  by a colon and a blank.  Then an error message corresponding to
    //    the current value of errno and a new-line.

    //    To be of most use, the argument string should include the name of the function that
    //    incurred the error.
	perror(str);
	exit(1);



}

int main(int argc, char *argv[])
{
    char *p = NULL;
    int fd;

    fd = open("testmap", O_RDWR|O_CREAT|O_TRUNC, 0644);
    //int open(const char *pathname, int flags, mode_t mode);
    //The mode argument specifies the file mode bits be applied when a new file is
    //created.  This argument must be supplied when O_CREAT or O_TMPFILE is specified in flags; if neither O_CREAT nor O_TMPFILE is specified, then  mode  is ignored.

    if(fd == -1){
        sys_err("open");
    }

    //     The  truncate()  and  ftruncate() functions cause the regular file named by path or
    //    referenced by fd to be truncated to a size of precisely length bytes.
    ftruncate(fd, 20);
    int len = lseek(fd, 0, SEEK_END);
    //返回值：成功：较起始位置偏移量  失败：-1 errno

    p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    if(p == MAP_FAILED){
        sys_err("mmap error");
    }

    strcpy(p, "hello mmap"); 
    printf("-------------%s\n", p);

    int ret = munmap(p, len);
    if (ret == -1) {
        sys_err("munmap error");
    }
    return 0;
}