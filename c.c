#include<stdio.h>
#include<stdlib.h>


struct abc
{
	int data;
	struct abc* next;
};


int main()
{
	struct abc p, temp;
	p = (abc*)malloc(sizeof(abc));
	p.data = 1;
	//temp = (abc*)malloc(sizeof(abc));
//	p.next = temp;
//	p.data = 2;
	printf("%d\n",p.data);	
	return 0;
}
