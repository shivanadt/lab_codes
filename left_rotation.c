#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, d;
	int ii = 0;
	scanf("%d %d", &n, &d);
	int arr[n];
	int i;
	for(i = 0;i<n;i++) {
		arr[i] = i;
	}
	int jj;
	int kk;
	int A[n];
	for(ii=0;ii<n - d -1;ii++) {
		A[ii] = arr[d + ii];
	}
	for(jj = 0;jj<=d - 1;jj++) {
		A[n -d - 1 + jj] = arr[jj];
	}
	for(kk = 0;kk<n;kk++) {
		printf("%d ",A[kk]);
	}
	return 0;
}
