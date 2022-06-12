#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

//#include "mymath.h"
//#include "mymath.h"
//#include "mymath.h"

int mul(int,int);

int mul(int a, int b){
    return (a*b);
}

int main(int argc, int *argv[]) {
    int a=4, b=4;
    printf("%d+%d=%d\n",a,b,add(a,b));
    printf("%d-%d=%d\n",a,b,sub(a,b));
    printf("%d/%d=%d\n",a,b,div1(a,b));

    printf("%d*%d=%d\n",a,b,mul(a,b));
    return 0;
}
