#include<stdio.h>
#include<malloc.h>

#define D_type float

typedef struct
{
	D_type *data;
	int count;
}Coll;

typedef struct{
	int curr;
	Coll C;
}heap;

D_type delete_heap(heap *h)  //Change return dataype
{
	int pos, l, r, largest_pos;
	D_type temp,return_val;  //Change here for int and float
	pos = 0;
	return_val = h->C.data[pos];
		
	h->curr = h->curr-1;
	h->C.data[pos] = h->C.data[h->curr];
		
	l = pos*2 +1;
	r = l +1;
	
	while(pos<h->curr&&l<=h->curr||r<=h->curr)
	{
		if(l<=h->curr)
		{
			largest_pos = l;	
		}
		if(r<=h->curr && h->C.data[r]>h->C.data[largest_pos])
		{
			largest_pos = r;
		}
		temp = h->C.data[pos];
		h->C.data[pos] = h->C.data[largest_pos];
		h->C.data[largest_pos] = temp;	
			
		pos = largest_pos;
			
		l = pos*2 +1;
		r = l +1;	 
	}
		
	return return_val;
}

int insert_heap(heap *h, D_type data)  
{
	int p,pos;
	pos = h->curr;
	p = (h->curr-1)/2;
	h->C.data[h->curr] = data;
	while(h->C.data[p]<h->C.data[pos])
	{

		if(h->C.data[p]<=h->C.data[pos])
		{
			D_type temp = h->C.data[p];    //Change here for int and float
			h->C.data[p] = h->C.data[pos];
			h->C.data[pos]=temp;
			pos = p; 
			p = (p-1)/2;
		}
			
	}
	
	h->curr++;
	return 0;
}

int initialize(Coll *C, int n)
{
	if(n<1)
	{
		C->count=0;
		C->data = NULL;
		return(-1); 
	}
	C->count = n;
	C->data = (D_type*)malloc(sizeof(D_type) * C->count);
	return 0;	
}
int release(Coll *c)
{
	free(c->data);
	c->data=NULL;
	return(0);
}
int initialize_heap(heap *h, int max)
{
	int temp;
	h->curr = 0;
	temp = initialize(&(h->C), max);
	return(temp);
}

int disp(Coll *A)
{
	int i;
	printf("\nSorted Data: ");
	for(i=0;i<A->count;i++)
	{
		printf("%f ", A->data[i]);    //Change here for int and float
	}
	return 0;
}

int main()
{
	heap h;
	int size,i;
	D_type retval;
	printf("Enter size of heap");
	scanf("%d", &size);
	i=initialize_heap(&h, size);
	if(i==-1)
	{
		printf("Failed to create heap");
		return 0;
	}
	printf("Enter %d numbers", size);
	for(i=0;i<size;i++)
	{
		scanf("%f", &h.C.data[i]);   //Change here for int and float
	}
	h.curr = 0;
	for(i=0;i<h.C.count;i++)
	{
		insert_heap(&h, h.C.data[i]);
	}
	for(i=0;i<h.C.count;i++)
	{
		retval = delete_heap(&h);
		h.C.data[h.curr] = retval;
	}
    disp(&h.C);
    release(&h.C);
	return 0;
}

