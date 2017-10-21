#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 1000

int heap[MAX], heap_size;

void Init()
{
	heap_size = 0;
	heap[0] = -INT_MAX;
}

void Insert(int element)
{	
	heap_size++;
	heap[heap_size] = element;
	int now = heap_size;
	while(heap[now/2] > element) {
	heap[now] = heap[now/2];
	now /= 2;
	}
	heap[now] = element;
}

int DeleteMin()
{
	int minElement, lastElement, child, now;
	minElement = heap[1];
	lastElement = heap[heap_size--];
	for(now = 1; now*2 <= heap_size; now = child) {
		child = now*2;
		if(child != heap_size && heap[child + 1] < heap[child]) {
			child++;
	}
		if(lastElement > heap[child]) {
			heap[now] = heap[child];

		} else {
			break;
		}
	}
	heap[now] = lastElement;
	return minElement;	
}

int main()
{
	int number_of_elements;
	    printf("Program to demonstrate Heap:\nEnter the number of elements: ");

    scanf("%d", &number_of_elements);

    int iter, element;

    Init();

    printf("Enter the elements: ");

    for (iter = 0; iter < number_of_elements; iter++) {

        scanf("%d", &element);

        Insert(element);

    }

    for (iter = 0; iter < number_of_elements; iter++) {

        printf("%d ", DeleteMin());

    }

    printf("\n");
	

	return 0;
}
