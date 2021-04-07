/*
write a program in C to fulfill the following requiremnets.
Declare a structure that can store exactly n numbers (n is user given integer) of user given data.
Write a function to enter the data to a variable of the above type structure.
Write a function to Display the content of a variable of the above type structure.
Try to make the program generic so that the program can be used for different datatypes with minimal modification in the program.
*/
#include<stdio.h>
#include<stdlib.h>

#define D_TYPE int

struct position
{
	int start;
	int end;
};
typedef struct position POS;

struct stack
{
	POS *ptr;
	int tos;
	//struct stack *ptr;
};
typedef struct stack STACK;

struct array{
	D_TYPE *ptr;
	int n;
};
typedef struct array ARRAY;

int is_empty(STACK *S)
{
	if(S->tos==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int push(STACK *S, POS P)
{
	S->tos=S->tos+1;
	S->ptr[S->tos] = P;
	return 0;
}
POS pop(STACK *S)
{
	if(is_empty(S))
	{
		return;
	}
	else
	{
		POS P;
		P = S->ptr[S->tos];
		S->tos = S->tos - 1;
		return P;
	}
	
}


int find_largest(ARRAY *A,int curr)
{
	int largest, pos,i;
	largest = A->ptr[curr];
	pos = curr;
	for(i=0;i<curr;i++)
	{
		if(A->ptr[i]>largest)
		{
			largest = A->ptr[i];
			pos = i;
		}
	}
	return pos;
}

int selection_sort(ARRAY *A)
{
	int i,j,k,largest_pos, largest, temp;
	k = A->n-1;
	largest = A->ptr[k];
	largest_pos = k;
	
	for(i=0;i<A->n;i++)	
	{
		//largest_pos = find_largest(A, j);
		
		for(j=0;j<=k;j++)
		{
			if(A->ptr[j]>largest)
			{
				largest = A->ptr[j];
				largest_pos = j;
			}
		}
		temp=A->ptr[largest_pos];
		A->ptr[largest_pos] = A->ptr[k];
		A->ptr[k] = temp;
		k--;
		largest = A->ptr[k];
		largest_pos = k;
	}
	return 0;
}

int insertion_sort(ARRAY *A)
{
	int i,j,tmp;
	
	for(i=0;i<A->n;i++)
	{
		tmp = A->ptr[i];
		for(j=i-1;j>=0;j--)
		{
			if(tmp<A->ptr[j])
				A->ptr[j+1] = A->ptr[j];
			else
			{
				break;
			}
		}
		A->ptr[j+1] = tmp;
	}
	return 0;
	
}

int quick_sort(ARRAY *A)
{ 
	STACK S;
	S.tos = -1;
	S.ptr = (POS *)malloc(sizeof(POS) * A->n);
	POS P;
	int l,r,pivot, tmp, from, to, pos;
	P.start = 0;
	P.end = A->n-1;
	push(&S,P);
	while(!is_empty(&S))
	{
		P = pop(&S);
		//printf("Popped %d and %d", P.start, P.end);
		from = P.start;
		to = P.end;	
		l=from;
		r=to;
		pos = from;
		pivot = A->ptr[pos];
		printf("%d ", pivot);
		while(l<r)
		{
			while(l<r)
			{
				if(A->ptr[r]<pivot)
				{
					A->ptr[pos] = A->ptr[r];
					A->ptr[r] = pivot;
					pos = r;
					l++;
					break;
				}
				else
				{
					r--;
				}
			}
			while(l<r)
			{
				if(A->ptr[l]>=pivot)
				{
					A->ptr[pos] = A->ptr[l];
					A->ptr[l] = pivot;
					pos = l;
					r--;
					break;
				}
				else
				{
					l++;
				}
			}
			if(pos+1<to)
			{
				P.start = pos+1;
				P.end = to;
				push(&S, P);
			}
			if(from<pos-1)
			{
				P.start = from;
				P.end = pos -1;
				push(&S,P); 
			}
			
		}
		
	}
	
	return 0;	
}

int enter_data(ARRAY *A)
{
	int i;
	printf("Enter %d values: ", A->n);
	for(i=0;i<A->n;i++)
	{
		scanf("%d", &A->ptr[i]);
	}
	return 0;
}
int disp(ARRAY *A)
{
	int i;
	printf("\nEntered Data: ");
	for(i=0;i<A->n;i++)
	{
		printf("%d ", A->ptr[i]);
	}
	return 0;
}

int main()
{
	ARRAY A;
	int n,x;
	printf("Enter size of structure: ");
	scanf("%d",&A.n);
	if(A.n>0)
	{
		A.ptr = (D_TYPE*)malloc(sizeof(D_TYPE)*A.n);
		enter_data(&A);
		disp(&A);
		while(1)
		{
			printf("Enter Choice:\n");
			printf("1. Selection sort\n2. Insertion Sort\n3.Quick Sort.\n4. Display");
			scanf("%d", &x);
			switch(x)
			{
				case 1: selection_sort(&A);
						break;
				case 2: insertion_sort(&A);
						break;
				case 3: quick_sort(&A);
						break;		
				case 4: disp(&A);
						break;
				case 0: exit(0);
						break;
			}
			
		}
		
	}
	else
	{
		printf("Invalid size");
	}
	return 0;
}
