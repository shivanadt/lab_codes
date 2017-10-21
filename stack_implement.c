#include<stdio.h>

int push(int*, int, int);

int pop(int );

int is_empty(int );

int is_full(int );

int main()
{
	int arr[100];
	int top = -1;
	top = push(arr, top, 1);
	top = push(arr, top, 2);
	top = push(arr, top, 3);
	int num;
	num = is_empty(top);
	printf("%d\n", num);
	num = is_full(top);
	printf("%d\n",num);
	top = pop( top);
	top = pop( top);
	top = pop( top);
	num = is_empty(top);
	printf("%d\n",num);
	return 0;
}

int push(int a[], int top, int x)
{
	if(is_full( top )) return -999;
	top++;
	a[top] = x;
	return top;

}

int pop( int top)
{
	if(is_empty(top)) return -9999;
	top--;
	return top;
}

int is_full(int top)
{
	if(top == 99) return 1;
	else return 0;
}

int is_empty(int top)
{
	if(top == -1) return 1;
	else return 0;
}

