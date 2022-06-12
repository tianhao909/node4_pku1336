#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char *argv[]) {
    int ret = truncate("dict_fth.cp", 250);
    printf("ret = %d\n", ret);

    return 0;
}
