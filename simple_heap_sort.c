#include<stdio.h>
#include<malloc.h>

#define D_type int
#define DATATYPE int


typedef struct
{
	D_type *data;
	int count;
}Coll;

typedef struct{
	int curr;
	Coll *C;
}heap;

int delete_heap(heap *h)
{
	int temp, return_val,pos, l, r, largest, largest_pos;
	
		pos = 0;
		return_val = h->C->data[pos];
		
		h->curr = h->curr-1;
		h->C->data[pos] = h->C->data[h->curr];
		
		l = pos*2 +1;
		r = l +1;
	
		while(pos<h->curr&&l<=h->curr||r<=h->curr)
		{
			if(l<=h->curr)
			{
				largest =  h->C->data[l];
				largest_pos = l;	
			}
			if(r<=h->curr && h->C->data[r]>h->C->data[largest_pos])
			{
				largest =  h->C->data[r];
				largest_pos = r;
			}
			temp = h->C->data[pos];
			h->C->data[pos] = h->C->data[largest_pos];
			h->C->data[largest_pos] = temp;	
				
			pos = largest_pos;
			
			l = pos*2 +1;
			r = l +1;
			printf("pos %d l %d r %d curr %d \n", pos, l, r, h->curr);
			 
		}
		
	
	return return_val;
}

int insert_heap(heap *h, int data)
{
	printf("Entered for %d\n", h->curr);
	int p,l,r,pos;
	pos = h->curr;
	p = (h->curr-1)/2;
	//l = p*2 +1;
	//r = l +1;
	h->C->data[h->curr] = data;
	printf("Inserted %d at index %d\n", data, h->curr);
	while(h->C->data[p]<h->C->data[pos])
	{
		//printf("Here");
		if(h->C->data[p]<=h->C->data[pos])
		{
			int temp = h->C->data[p];
			//h->C->data[p] = h->C->data[h->curr];
			//h->C->data[h->curr]=temp;
			h->C->data[p] = h->C->data[pos];
			h->C->data[pos]=temp;
			pos = p;
			printf("Position of %d was changed to index %d\n", data, p);  
			p = (p-1)/2;
		}
			
	}
	
	h->curr++;
	return 0;
}

initialize(Coll *C)
{
	printf("Enter size of array: ");
	scanf("%d",&C->count);
	C->data = (D_type*)malloc(sizeof(D_type) * C->count);
	return C;	
}

int initialize_heap(heap *h, int max)
{
	int temp;
	h->curr = 0;
	temp = initialize(h->C);
	return(temp);
}

int disp(Coll *A)
{
	int i;
	printf("\nEntered Data: ");
	for(i=0;i<A->count;i++)
	{
		printf("%d ", A->data[i]);
	}
	return 0;
}

int main()
{
	Coll A;
	heap h;
	int retval;
	A.count = 10;
	A.data = (D_type*)malloc(sizeof(D_type) * A.count);
	
	//enter data
	int i;
	
	printf("Enter %d values: ", A.count);
	for(i=0;i<A.count;i++)
	{
		scanf("%d", &A.data[i]);
	}
	//disp(&A);
	h.curr = 0;
	h.C = &A;
	
	for(i=0;i<A.count;i++)
	{
		insert_heap(&h, A.data[i]);
	}
	disp(&A);
	for(i=0;i<A.count;i++)
	{
		printf("Entered\n");
		retval = delete_heap(&h);
		h.C->data[h.curr] = retval;
		disp(&A);
	}
    disp(&A);
	return 0;
}

