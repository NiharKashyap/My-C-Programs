#include<stdio.h>
#include<malloc.h>

#define D_type int

typedef struct
{
	D_type *data;
	int count;
}Coll;

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct Queue
{
	node *front, *rear;
}Queue;

int isEmpty(Queue *q)
{
	return (q->rear == NULL || q->front == NULL);
}

int enque(Queue *q, D_type d)
{
	node *NODE;
	NODE = (node*)malloc(sizeof(node));
	NODE->data = d;
	NODE->next = NULL;

	if(isEmpty(q))
	{
		q->front=NODE;
	}
	else
	{
		q->rear->next = NODE;
	}
	q->rear=NODE;
	
	return 0;
}

D_type deque(Queue *q)
{
	D_type data;
	node *temp;
	if(isEmpty(q)){
		
		return -1;
	}
	temp = q->front;
	data = temp->data;
	q->front = q->front->next;
	free(temp);
	return data;
}

int display(Coll *A)
{
	int i;
	printf("\nSorted Data: ");
	for(i=0;i<A->count;i++)
	{
		printf("%x ", A->data[i]);    //Change here for int and hex
	}
	return 0;
}
int release(Coll *c)
{
	free(c->data);
	c->data=NULL;
	return(0);
}
int radix_sort(Coll C, int r)
{
	int i,j,dig,temp,bi,dc, largest;
	Queue *bucket;
	
	bucket = (Queue*)malloc(sizeof(Queue) * r);
	
	for(i=0;i<r;i++)
	{
		bucket[i].front = NULL;
		bucket[i].rear = NULL;
	}
	
	largest = C.data[0];
	for(i=0;i<C.count;i++)
	{
		
		if(largest<C.data[i])
			largest = C.data[i];
	}
	dig=0;
	while(largest!=0)
	{
		dig++;
		largest = largest/r;
	}
	
	for(i=0;i<dig;i++)
	{
		for(j=0;j<C.count;j++)
		{
			temp = C.data[j];
			dc=0;
			do
			{
				bi = temp%r;
				temp = temp/r;
				dc++;
			}
			while(dc<=i);
			
			enque(&bucket[bi], C.data[j]);
			
		}
		dc = 0;
		for(j=0;j<r;j++)
		{
			while(!isEmpty(&bucket[j]))
			{
				temp=deque(&bucket[j]);
				C.data[dc] = temp;
				dc++;
			}
		}
	}
	return 0;
}
int main()
{
	Coll C;
	int size,i;
	printf("Enter size of list");
	scanf("%d",&C.count); 
	printf("Enter %d values:\n", C.count);
	C.data = (D_type*)malloc(sizeof(D_type)*C.count);
	for(i=0;i<C.count;i++)
	{
		scanf("%x", &C.data[i]);   //Change here for int and hex
	}
	radix_sort(C, 16);
	display(&C);
    release(&C);
	return 0;
}

