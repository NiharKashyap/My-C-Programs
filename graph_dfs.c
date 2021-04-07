#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
	int data;
	struct list *next;
}list;

typedef struct stack
{
	list *top;
}stack;

typedef struct EDGE
{
	int from;
	int to;
	int weight;
}EDGE;

typedef struct NODE
{
	EDGE info;
	struct NODE *next;
}NODE;

 typedef struct QUEUE
{
	NODE *front;
	NODE *rear;
}QUEUE;

typedef struct GRAPH
{
	int n_nodes;
	struct QUEUE *p;
}GRAPH;

int stack_is_empty(stack *S)
{
	if(S->top==NULL)
		return 1;
	
	return 0;
}

int push(stack *S, int d)
{
	list *t;
	t = (list*)malloc(sizeof(list));
	t->data = d;
	t->next = NULL;
	if(S->top==NULL)
	{
		S->top = t;
		return;
	}
	t->next = S->top;
	S->top = t;
	return 0;
}
int pop(stack *s)
{
	int d;
	list *l;
	d=s->top->data;
	l=s->top;
	s->top = s->top->next;
	free(l);
	return d;
}


int enque(QUEUE *g, EDGE e)
{
		NODE *node;
		node = (NODE *)malloc(sizeof(NODE));
		node->info = e;
		node->next = NULL;
		
		if(is_empty(g->front))
		{
			
			g->front = node;
		}
		else
		{
			
			g->rear->next = node;
		}
		g->rear = node;
		
		printf("\nNode Added\n");
		
		return 0;
}

int deque(struct QUEUE *g)
{
	
	struct NODE *tmp;
	
	tmp = g->front;
	
	g->front = tmp->next;
	tmp->next = NULL;
	
	
	printf("\nNode Removed\n");
	return 0;
}

is_empty(struct QUEUE *q)
{
	int i;
	
		if(q==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
	
}

int initialize(GRAPH *g)
{
	int i,nums;
	printf("Enter number of Queues");
	scanf("%d", &nums);
	if(nums<0)
	{
		g->n_nodes = -1;
		printf("Cannot create negative queue");
		return;
	}
	else
	{
		g->n_nodes = nums;
		g->p = (struct QUEUE *)malloc(sizeof(struct QUEUE) * nums);
	
		for(i = 0; i < nums; i++)
		{
		
		g->p[i].front = NULL;
		g->p[i].rear = NULL;
		
		}
	}
	return 0;
	
}

int Add_edge(struct EDGE e, struct GRAPH *g)
{
		
	enque(&g->p[e.from], e);
	//enque(g, e);
	return 0;
}
int Rem_edge(struct GRAPH *g)
{
	struct NODE *tmp, *ftmp;
	int from, to;
	printf("Enter from vertex to remove");
	scanf("%d", &from);
	printf("Enter to vertex to remove");
	scanf("%d", &to);
	
	tmp = g->p[from].front;
	
	while(tmp->info.to!=to)
	{
		ftmp = tmp;
		deque(&g->p[from]);
		enque(&g->p[from],ftmp->info);
		tmp = g->p[from].front;
	}
	deque(&g->p[from]);
	return 0;
}
int Rel_MEM(struct GRAPH *g)
{
	struct NODE *tmp;
	int i;
	
	for(i=0;i<g->n_nodes;i++)
	{
		while(g->p[i].front!=NULL)
		{
			tmp=g->p[i].front;
			g->p[i].front = tmp->next;
			free(tmp);
		}		
	}
	free(g->p);
	g->n_nodes=0;
	printf("Graph is now empty");
	return 0;
}
int disp(struct GRAPH *g)
{
	if(g->n_nodes<1)
	{
		printf("The graph is empty");
	}
	else
	{
		int i;
		struct NODE *tmp;
		for(i=0;i<g->n_nodes;i++)
		{
		tmp = g->p[i].front;
		while(tmp!=NULL)
		{
			printf("(%d -> %d) Weight %d\n", tmp->info.from, tmp->info.to, tmp->info.weight);
            tmp = tmp->next;		
		}
		}	
		
	}
	
	
	return 0;
}
int helper_add(struct GRAPH *g)
{
	struct EDGE e;
	printf("Enter from vertex ");
	scanf("%d", &e.from);
	printf("Enter to vertex ");
	scanf("%d", &e.to);
	printf("Enter weight of vertex ");
	scanf("%d", &e.weight);
	if(e.from!=e.to&&g->n_nodes>0&&e.weight>0)
	{
		Add_edge(e,g);
	}
	else
	{
		printf("Operation invalid\n");
	}
	return 0;
}
int explore(int curr)
{
	printf("%d ", curr);
}
int dfs(struct GRAPH *g, int start)
{
	stack *S;
	struct NODE *tmp;
	int curr,i,j;
	char *status;
	
	S = (stack *)malloc(sizeof(stack));

	S->top = NULL;
	
	
	status = (char *)malloc(sizeof(char) * (g->n_nodes));
	
	
	
	for(j=0;j<g->n_nodes;j++)
	{
		status[j]=0;
	}
	
	push(S, start);
	while(!stack_is_empty(S))
	{
		curr = pop(S);
		
		
		if(status[curr]==0)
		{
			
			explore(curr);
			status[curr]=1;
			
			tmp = g->p[curr].front;
			while(tmp!=NULL)
			{
				i=tmp->info.to;
			
				if(status[i]==0)
				{
					push(S,i);
				}
				tmp = tmp->next;
			}
		}
	}
	return 0;
}
int main()
{
	
	int choice, d,x, from, to, weight, count;
	

	struct GRAPH *ptr = (struct GRAPH *)malloc(sizeof(struct GRAPH));
	ptr->n_nodes = 0;
	do
	{
		printf("\nPlease Choose an operation\n");
		printf("1. Initialize Graph\n2. Add Edge\n3. Remove Edge\n4. Show Edge\n5. Relase Memory\n6. DFS traversal\n0. Exit program\n");
		scanf("%d", &x);
		switch(x)
		{
			case 1:
				initialize(ptr);
				break;
			case 2:
				//add edge
				helper_add(ptr);
				break;
			case 3:
				//remove edge
				Rem_edge(ptr);
				break;
			case 4:
				//show edge
				disp(ptr);
				break;
			case 5:
				//release memeory
				Rel_MEM(ptr);
				break;
			case 6:
				printf("Enter start vertex: ");
				scanf("%d", &d);
				dfs(ptr, d);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Invalid choice");		
		}
		
	}
	while(1);
	
	
}
