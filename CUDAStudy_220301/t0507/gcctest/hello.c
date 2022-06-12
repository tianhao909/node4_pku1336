#include "hello.h"

#ifdef HELLO
#define HI 20
#endif

int main(int argc, char *argv[]) {
    int b = 10;
    int a = 10;
    printf("---------------%d\n", HI);
    
    return 0;
}