#include<stdio.h>
#include<stdlib.h>

//Stores each term of poynomial
struct node
{
	int coeff;
	int pow;
	struct node *next;	
};

typedef struct node node;

//Queue to store polynomial
struct queue
{
	 node *front;
	 node *rear;
};

typedef struct queue queue;
//Check for empty queue
is_empty(queue *q)
{
	
	if(q->front==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Enques the coefficient and power of each term
int enque(queue *q, int coff, int pow)
{
	node *tmp;
	tmp = ( node *)malloc(sizeof(node));
	
	if(tmp==NULL)
	{
		printf("Error: Could not allocate memory\n");
		return;
	}
	
	tmp->coeff = coff;
	tmp->pow = pow;
	tmp->next= NULL;
	
	if(is_empty(q))
	{
		q->front=tmp;
	}
	else
	{
		q->rear->next = tmp;
	}
	q->rear=tmp;
	return 0;
}

//Removes node from queue
int deque(queue *q)
{
	node* n;
	n = (node *)malloc(sizeof(node));
	n = q->front;
	if(is_empty(q))
	{
		printf("Queue is empty\n");
	}
	else
	{
		q->front = q->front->next;
		n->next = NULL;
		free(n);
	}
	return 0;
}
//Enter each term of polynomial one by one
int enter_poly(queue *q)
{
	int coeff,pow;
	printf("Enter coefficient of polynomial\n");
	scanf("%d", &coeff);
	printf("Enter exponent of polynomial\n");
	scanf("%d", &pow);
	
	if(pow<0)
	{
		printf("The power of a polynomial cannot be negative\n");
		printf("Please enter again\n");
		return;
	}
	else if(coeff==0)
	{
		printf("The term became 0 since the coefficient was 0\n");
		printf("Please enter again\n");
		return;
	}
	
	
	if(q->front==NULL)
	{
		enque(q,coeff, pow);
	}
	else
	{
		if(pow<=q->rear->pow)
		{
			printf("The exponent must be greater than the previously entered exponent\n");
		}
		else
		{
			enque(q,coeff, pow);
		}
	}
	return 0;
}
//Add two polynomial resulting in third
int add_poly( queue *q1,  queue *q2)
{
	if(is_empty(q1)||(is_empty(q2)))
	{
		printf("No polynomial to add\n");
		return;
		
	}
	printf("After addition new ");
	node *n1, *n2;
	queue *q3;
	q3 = (queue*)malloc(sizeof(queue));
	q3->front = NULL;
	q3->rear = NULL;
	
	n1 = (node*)malloc(sizeof(node));
	n2 = (node*)malloc(sizeof(node));	

	
	n1 = q1->front;
	n2 = q2->front;
	
	while(n1||n2)
	{
		if(n1==NULL)
		{
			enque(q3, n2->coeff, n2->pow);
			n2 = n2->next;
		}
		else if(n2==NULL)
		{
			enque(q3, n1->coeff, n1->pow);
			n1 = n1->next;
		}
		else
		{
			if(n1->pow>n2->pow)
			{
				enque(q3, n2->coeff, n2->pow);
				n2 = n2->next;
			}
			else if(n1->pow<n2->pow)
			{
				enque(q3, n1->coeff, n1->pow);
				n1 = n1->next;
			}
			else
			{
				enque(q3, n1->coeff + n2->coeff, n1->pow);
				n1 = n1->next;
				n2 = n2->next;
				
			}
		}
		
	}
	
	disp(q3);
	
	return 0;
}
//substract two poly resulting in third
int sub_poly(queue *q1,  queue *q2)
{
	if(is_empty(q1)||(is_empty(q2)))
	{
		printf("No polynomial to subtract\n");
		return;
	}
	
	printf("After subtraction new ");
	node *n1, *n2;
	int coeff;
	queue *q3;
	
	q3 = (queue*)malloc(sizeof(queue));
	
	q3->front = NULL;
	q3->rear = NULL;
	
	n1 = (node*)malloc(sizeof(node));
	n2 = (node*)malloc(sizeof(node));	

	
	n1 = q1->front;
	n2 = q2->front;
	
	while(n1||n2)
	{
		if(n1==NULL)
		{
			coeff =-1*n2->coeff;
			enque(q3, coeff, n2->pow);
			n2 = n2->next;
		}
		else if(n2==NULL)
		{
			enque(q3, n1->coeff, n1->pow);
			n1 = n1->next;
		}
		else
		{
			if(n1->pow>n2->pow)
			{
				coeff =-1*n2->coeff;
				enque(q3, coeff, n2->pow);
				n2 = n2->next;
			}
			else if(n1->pow<n2->pow)
			{
				enque(q3, n1->coeff, n1->pow);
				n1 = n1->next;
			}
			else
			{
				coeff =-1*n2->coeff;
				enque(q3, n1->coeff + coeff, n1->pow);
				n1 = n1->next;
				n2 = n2->next;
				
			}
		}
		
	}
	
	disp(q3);
	
	return 0;
}
//Sorting linked list after the multiply operation
node* sort(node *n)
{
	int min;
	node *n1, *n2;
	
	n1 = n;
	n2 = n1->next;

	while(n1)
	{
		while(n2)
		{
			if(n1->pow<n2->pow)
			{
				node *tmp;
				
				tmp =(node*)malloc(sizeof(node));
				
				tmp->pow = n1->pow;
				tmp->coeff=n1->coeff;
				
				n1->pow = n2->pow;
				n1->coeff= n2->coeff;
				
				n2->pow = tmp->pow;
				n2->coeff= tmp->coeff; 
			}
			n2 = n2->next;
		}
		n1 = n1->next;
		n2 = n;
	}
	
	return n;
	
}

//Multiply polynomial
int multiply(queue *q1, queue *q2)
{
	if(is_empty(q1)||(is_empty(q2)))
	{
		printf("No polynomial to multiply\n");
		return;
		
	}
	queue *q3;
	
	q3 = (queue*)malloc(sizeof(queue));
	
	node *n1,*n2, *n3, *n4, *tmp;
	
	n3=NULL;
	
	n1 = q1->front;
	n2 = q2->front;
	
	
	while(n1)
	{
		while(n2)
		{
			tmp = (node*)malloc(sizeof(node));
			tmp->coeff = n1->coeff * n2->coeff;
			tmp->pow = n1->pow + n2->pow;
			tmp->next = NULL;
				
			if(n3==NULL)
			{
				n3 = tmp;
				n4 = n3;
			}
			else
			{
				n3->next = tmp;
				n3 = tmp;
			}
			n2 = n2->next;
		}
		n2 = q2->front;
		n1=n1->next;
	}
	
	node *n5 = sort(n4);
	
	//n1 will point n2 and n5 for traverse
	n1 = n5;
	n2 = n5->next;
	
	while(n2)
	{
		int d1, d2;
		d1 = n1->pow;
		d2 = n2->pow;
	
		if(d1==d2)
		{
			n1->coeff = n1->coeff + n2->coeff;
			
			n2 = n2->next;
			n1->next = n2;
		}
		n1 = n1->next;
		n2 = n2->next;
	}
	
	
	q3->front = NULL;
	q3->rear = NULL;
	printf("After multiplication new ");
	while(n5)
	{
		enque(q3, n5->coeff, n5->pow);
		n5 = n5->next;
	}
	
	disp(q3);
	return 0;

}
//Find order of polynomial
int order(queue *q)
{
	if(is_empty(q))
	{
		printf("Operation denied on empty queue\n");
		return;
		
	}
	node *n1;
	n1 = (node *)malloc(sizeof(node));
	n1 = q->rear;
	printf("Order of the polynomial is %d", n1->pow);
	return 0;
}
//Reset the polynomial to 0
int reset(queue *q)
{
	while(q->front)
	{
		deque(q);
	}
	printf("The polynomial has been reset\n");
	return 0;
}
//Display the polynomial: Display in the form of (a,b) where a is exponent b is coeff
int disp( queue *q)
{
	if(is_empty(q))
	{
		printf("There is nothing to display\n");
		return;
		
	}
	node *tmp;
	tmp = ( node *)malloc(sizeof(node));
	tmp = q->front;
	printf(" polynomial: ");
	while(tmp!=NULL)
	{
		printf("(%d, %d) ", tmp->pow, tmp->coeff);
		tmp = tmp->next;
	}
	return 0;
}
//Evaluate polynomial for a value of x
int evaluate(queue *q, int x)
{
	if(is_empty(q))
	{
		printf("Cannot evaluate for empty polynomial\n");
		return;
		
	}
	printf("The expression is evaluated to ");
	node *n;
	n = (node*)malloc(sizeof(node));
	int i,tmp=0, term=1;
	n = q->front;
	while(n!=NULL)
	{
		
		for(i=0;i<n->pow;i++)
		{
			term = term * x;
		} 
		tmp = tmp + term * n->coeff;
		n = n->next;
	}
	printf("%d\n", tmp);
	return 0;
}

int main()
{
	queue ptr1, ptr2;
	
	ptr1.front = NULL;
	ptr1.rear = NULL;
	
	ptr2.front = NULL;
	ptr2.rear = NULL;
	
	int choice, x;
	
	do
	{
		
		printf("\n1. Enter first polynomial\n2. Enter second polynomial\n3. Add two polynomial\n4. Subtracting one polynomial from another\n");
		printf("5. Multiply two polynomials\n6. Evaluate the first polynomial\n7. Evaluate the second polynomial\n8. Order of first polynomial\n");
		printf("9. Order of second polynomial\n10. Reset first polynomial\n11. Reset second polynomial\n");
		printf("12. Display first polynomial\n13. Display second polynomial\n14. Exit\n");
		
		printf("\nEnter Your choice: \n");

		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				//enter first poly		
				enter_poly(&ptr1);
				break;
			case 2:
				//enter second poly
				enter_poly(&ptr2);
				break;
			case 3:
				add_poly(&ptr1,&ptr2);
				break;
			case 4:
				//subtract poly
				sub_poly(&ptr1,&ptr2);
				break;
			case 5:
				//multiply
				multiply(&ptr1, &ptr2);
				break;
			case 6:
				//evaluate first polynomial
				printf("Enter the value of X ");
				scanf("%d", &x);
				evaluate(&ptr1, x);
				break;
			case 7:
				//evaluate second polyomial
				printf("Enter the value of X ");
				scanf("%d", &x);
				evaluate(&ptr2, x);
				break;
			case 8:
				//order of first poly
				order(&ptr1);
				break;
			case 9:
				//order of second poly
				order(&ptr2);
				break;	
			case 10:
				//reset first poly
				reset(&ptr1);
				break;
			case 11:
				//reset second poly
				reset(&ptr2);
				break;
			case 12:
				//disp first poly
				disp(&ptr1);
				break;
			case 13:
				//dis second poly
				disp(&ptr2);
				break;
			case 14:
				exit(0);
				break;
			default:
				printf("Invalid option\n");
		}
			
	}
	while(1);
	
	return 0;
}

