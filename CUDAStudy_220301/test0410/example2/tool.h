//#include<stdio.h>

int find_max(int arr[], int n ) {
	int m = arr[0];
	int i;
	for (i = 0; i<n; i++) {
		if(arr[i]  > m) {
			m = arr[i];
		}
	}
	return m;
}
