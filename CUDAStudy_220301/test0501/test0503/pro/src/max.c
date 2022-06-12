#include "max.h"
int max(int a, int b, int c) {
    int max = a;
    if (max <= b ) {
        max = b;
    }
    if (max <= c) {
        max = c;
    }
    printf("max=%d\n",max);
    return max;
}