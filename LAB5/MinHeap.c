#include<stdio.h>
#define max 50
int heap[max]; // The Heap
int n; //Number of elements
void heapify();
void maxheapify(int i);
void insert(int var);
void delete(int var);
int main() {
	printf("\nEnter the number of elements to be inserted : ");
	scanf("%d",&n);
	printf("\nEnter the elements of the heap : ");
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&heap[i]);
	heapify();
	while(1){
		int c;
		printf("\n1.Insert\n2.Delete\n3.Exit\nEnter your Choice : ");
		scanf("%d",&c);
		int ele=0;
		switch(c){
			case 1:{
				printf("\nEnter the element to be inserted : ");
				scanf("%d",&ele);
				insert(ele);
				break;
			}
			case 2:{
				printf("\nEnter the element to be deleted : ");
				scanf("%d",&ele);
				delete(ele);
				break;
			}
			case 3: return 0;
		}
		heapify();
		printf("\nHeap is :\n");
		for(i=0;i<n;i++)
			printf("\n%d",heap[i]);
	}
	return 0;
}
void minheapify(int i){
    int small = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && heap[l] < heap[small])
        small = l;
    if (r < n && heap[r] < heap[small])
        small = r;
    if (small != i){
    	int tmp = heap[i];
        heap[i]=heap[small];
        heap[small]=tmp;
        minheapify(small);
    }
}
void heapify(){
	int i;
	for (int i = n / 2 - 1; i >= 0; i--)
        minheapify(i);
}
void insert(int var){
	heap[n++] = var;
	return;
}
void delete(int var){
	int i;
	for(i=0;i<n;i++)
		if(heap[i]==var)
			break;
	if(i==n)
		printf("\nElement %d not found",var);
	else{
		heap[i] = heap[n-1];
		heap[n-1] = '\0';
		printf("\nElement %d deleted",var);
	}
}
