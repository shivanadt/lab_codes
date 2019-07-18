#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct node {
	int data;
	struct *next;	
}

int main()
{
	int n,q;
	int ii;
	long int x, y;
	int q_num;
	int lastanswer = 0;
	int temp;
	int len;
	
	// This program will try to demonstrate how dynamic array is created.
	scanf("%d %d ",n,q);
	for(ii = 0;ii<q;ii++) {
		scanf("%d %ld %ld",q_num, x, y);
		if(q_num == 1) {
			temp = (x^lastanswer)%n;
			len = sizeof(S[temp][]);
			S[temp][] = (long int*)calloc(sizeof(long int));
		}
	}
	
		

	return 0;
}
