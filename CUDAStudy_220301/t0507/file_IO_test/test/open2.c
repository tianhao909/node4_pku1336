#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]){
    int fd;
    //fd = open("/home/work/fth/CUDAStudy_220301/t0507/file_IO_test/test/resource/Makefile", O_RDONLY | O_CREAT, 0644);
    //fd = open("/home/work/fth/CUDAStudy_220301/t0507/file_IO_test/test/resource/Makefile_fth", O_RDONLY | O_CREAT | O_TRUNC, 0644);
    fd = open("./mydir", O_WRONLY, 0777);

    printf("fd= %d, errno=%d : %s\n",fd, errno, strerror(errno));
    close(fd);
    return 0;
}
