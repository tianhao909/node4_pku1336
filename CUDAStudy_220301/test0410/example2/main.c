#include "tool.h"
//#include"tool.c"
#include <stdio.h>

int main() {
	int arr[] = {1,8,3,4,5};
	int m = find_max(arr,5);
	printf("max = %d\n", m);

	return 0;
}
