#include <stdio.h>
#include "max.h"

int main() {
    int max1 =0;
    int a[3];
    for(int i=0; i<3; i++) {
        scanf("%d",&a[i]);
    }
    
    //max1 = max(1,2,3);
    max1 = max(a[0],a[1],a[2]);
    printf("max1=%d", max1);
    return 0;
}