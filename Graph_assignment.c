#include<stdio.h>
#include<stdlib.h>

#define N 6

struct EDGE
{
	int from;
	int to;
	int weight;
};

 struct NODE
{
	struct EDGE info;
	struct NODE *next;
};
 struct QUEUE
{
	struct NODE *front;
	struct NODE *rear;
};

struct GRAPH
{
	int n_nodes;
	struct QUEUE *p;
};

int enque(struct GRAPH *g, struct EDGE e)
{
		
		struct NODE *node;
		node = (struct NODE *)malloc(sizeof(struct NODE));
		node->info = e;
		node->next = NULL;
		
		if(is_empty(g->p[e.from].front))
		{
			
			g->p[e.from].front = node;
		}
		else
		{
			
			g->p[e.from].rear->next = node;
		}
		g->p[e.from].rear = node;
		
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
	//for(i=0;i<g->n_nodes;i++)
	
		if(q==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int initialize(struct GRAPH *g)
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
		//g = (struct GRAPH *)malloc(sizeof(struct GRAPH));
		g->n_nodes = nums;
		g->p = (struct QUEUE *)malloc(sizeof(struct QUEUE) * nums);
	
		for(i = 0; i < nums; i++)
		{
		//g->p[i] = (struct QUEUE *)malloc(sizeof(struct QUEUE) * nums);
		
		g->p[i].front = NULL;
		g->p[i].rear = NULL;
		
		}
	/*
		for(i = 0; i < nums; i++){
			printf("%d %d\n", g->p[i].front, g->p[i].rear);
		}
		
	return 0;
		*/	
	}
	
}

int Add_edge(struct EDGE e, struct GRAPH *g)
{
		
	//enque(g->p[e->from], e);
	enque(g, e);
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
		printf("\nHere");
		ftmp = tmp;
		deque(&g->p[from]);
		enque(g,ftmp->info);
		tmp = g->p[from].front;
		
	}
	printf("Here");
	deque(&g->p[from]);
	//printf("Edge to delete %d to %d",tmp->info.from, tmp->info.to);
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
	printf("Graph Attained Nirvana");
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
int main()
{
	
	int choice, d,x, from, to, weight, count;
	
	//e_ptr = &e;
	struct GRAPH *ptr = (struct GRAPH *)malloc(sizeof(struct GRAPH));
	ptr->n_nodes = 0;
	do
	{
		printf("\nPlease Choose an operation\n");
		printf("1. Initialize Graph\n2. Add Edge\n3. Remove Edge\n4. Show Edge\n5. Relase Memory\n0. Exit program\n");
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
			case 0:
				exit(0);
				break;
			default:
				printf("Invalid choice");		
		}
		
	}
	while(1);
	
	
}
