#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_TREE_HT 100

//A huffman tree node
struct MinHeapNode
{
	char data; //one of the input characters
	unsigned freq; //frequency of the character
	struct MinHeapNode *left, *right; // Left and right child of this node
}

//A Min Heap : collection of min heap (or huffman tree) nodes
struct MinHeap
{
	unsigned size;// current size of heap
	unsigned capacity;//capacity of min heap
	struct MinHeapNode **array; // Array of minheap node pointers
}

// A utility function allocate a new min heap node with given character 
// and frequency of the character
struct MinHeapNode* newNode(char data, unsigned freq)
{
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizrof(struct Min	HeapNode));
	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
}

//A utility function to swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

//The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)
{
	int smallest = idx;
	int left = 2*idx + 1;
	int right = 2*idx + 2;
	if(left < minHeap->size && minHeap -> array[left]->freq < minHeap->arr
		smallest = left;
	}
	if(right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
	smallest = right;
	if(smallest != idx) {
		sawpMinHeapNode(&minHeap->array[smallest], &minHeap->array[id]);
		minHeapify(minHeap, smallest);
	}

// A utility function to check if the size of head is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{
	return (minHeap->size == 1);
}

//A standard function to extract minimum value node from heap
struct MinHeapNode* extractMin(strcut MinHeap* minHeap)
{
	struct MinHeapNode* temp = moinHeap->array[0];
	minHeap->array[0] = minHeap->arrat[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
}	

//A utility function to insert a new node in Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
	++minHeap->size;
	int i = minHeap->size - 1;
	while(i && minHeapNode->freq < minHeap->array[(i - 1)/2]->freq) {
		minHeap->array[i] = minHeap->array[(i - 1)/2];
		i = (i - 1)/2;
	}
	minHeap->array[i] = minHeapNode;\
}

// A standard function to build min Heap
void buildMinHeap(struct MinHeap* minHeap)
{
	int n = minHeap->size - 1;
	int i;
	for(i = (n - 1)/2;i>=0; --i)
		minHeapify(minHeap, i);	
}

// A utility function to print array of size n
void printArr(int arr[], int n)
{
	int i;
	for(i = 0; i < n; ++i)
		printf("%d", arr[i]);
	printf("\n");
}

//Utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root)
{
	return !(root->left) && !(root->right);
}

//Create a min Heap of capacity equal to size and inserts all character of 
//data[] in min heap. Initially size of min heap is equal to capacity
struct MinHeap8 createAndBuildHeap(char data[], int freq[], int size)
{
	struct minHeap* minHeap = createMinHeap(size);
	int i;
	for(i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);
	minHeap->size = size;
	buildMinHeap(minHeap);
	return minHeap;
}

// the main function that builds huffman tree
struct MinHeapNode * buildHuffmanTree(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;
	
	// step 1: create min heap of capacity equal to size. Initially
	// there are modes equal to size.
	struct MinHeap = createAndBuildMinHeap(data, freq, size);
	
	//Iterate while size of heap doesn't become 1
	while(!isSizeOne(minHeap)) {
		// step 2:
}
