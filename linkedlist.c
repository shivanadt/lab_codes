#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node* CreateNode( int);
struct node* InsertNodeAtEnd(struct node*, int);
struct node* InsertNodeAtPosition(struct node*, int, int);
struct node* InsertNodeAtHead(struct node*, int);
struct node* DeleteANode(struct node*,  int);
void PrintNodes(struct node*);


// main driving function
int main()
{
	struct node* head;
	head = NULL;
	
	head = InsertNodeAtHead(head, 5);
	InsertNodeAtEnd(head, 6);
	InsertNodeAtEnd(head, 9);
	head = InsertNodeAtHead(head, 10);
	InsertNodeAtPosition(head, 11, 2);
	InsertNodeAtPosition(head, 15, 4);
	head = DeleteANode(head, 11);
	PrintNodes(head);

	return 0;
}

//Creating a new node
struct node*  CreateNode(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	return temp;
} 

// Function for inserting a new node
struct node* InsertNodeAtEnd(struct node* head, int x)
{
	struct node* temp = CreateNode(x);
	if(head == NULL) return temp;
	struct node* root;
	root = head;
	while(root->next != NULL) {
		root = root->next;
	}
	root->next = temp;
	return head;
}

//Function for inserting a new node at a given position 
struct node* InsertNodeAtPosition(struct node* head, int x, int pos)
{
	if(head == NULL) return CreateNode(x);
	struct node* root;
	struct node* temp;
	root = head;
	while(pos > 1) {
		root = root->next;
		pos--;
	}
	if(root->next == NULL) {
		root->next = CreateNode(x);
		return head;
	}
	 temp = root->next;
	root->next = CreateNode(x);
	root = root->next;
	root->next = temp;
	return head;
}

//fucntion to inset a node at the head of the linked list
struct node* InsertNodeAtHead(struct node* head, int x)
{
	if(head == NULL) return CreateNode(x);
	struct node* temp = CreateNode(x);
	temp->next = head;
	head = temp;
	return head;
}

//function to delete a node having x in the data field
struct node* DeleteANode(struct node* head, int x)
{
	if(head == NULL) return NULL;
	struct node *root, *temp;
	root = head;
	if(root->data == x) {
		head = head->next;
		free(root);
		return head;
	}
	while(root->data != x) {
		temp = root;
		root = root->next;
		if(root == NULL) return NULL;
	}
	temp->next = root->next;
	free(root);
	return head;
}

//function to print all the elements of the linked list
void PrintNodes(struct node* head)
{
	if(head == NULL) return;
	struct node* root = head;
	while(root != NULL) {
		printf("%d\n", root->data);
		root = root->next;
	}
	return;
}
