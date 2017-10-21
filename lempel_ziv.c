#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	int code;
	struct node*  next;
}

int main()
{
	struct node* head;
	head = (struct node*)malloc(sizeof(struct node));
	head->code = 1;
	head->next = NULL;
	
	return 0;
}
