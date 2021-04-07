#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
	int data;
	struct list *next;
}list;

struct queue
{
	list* front;
	list* rear;	
};

typedef struct queue queue;

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
int queue_is_empty(queue *q)
{
	if(q->front==NULL)
		return 1;
	
	return 0;
}
int bfs_enque(queue *q, int d)
{
	list *t;
	t = (list*)malloc(sizeof(list));
	t->data = d;
	t->next = NULL;
	
	if(queue_is_empty(q))
	{
		q->front =t;	
	}
	else
	{	
		q->rear->next=t;
	}
	q->rear = t;
	
	return 0;
}
int bfs_deque(queue *q)
{
	int d;
	list *t;
	d=q->front->data;
	t = q->front;
	q->front = q->front->next;
	//free(t);
	return d;
}


int enque(struct QUEUE *Q, struct EDGE e)
{
		struct NODE *node;
		node = (struct NODE *)malloc(sizeof(struct NODE));
		
		if(node==NULL)
		{
			return -1;
		}
		
		node->info = e;
		node->next = NULL;
		
		if(is_empty(Q->front))
		{
			Q->front = node;
		}
		else
		{
			Q->rear->next = node;
		}
		Q->rear = node;
		
		return 0;
}

int deque(struct QUEUE *Q)
{
	
	struct NODE *tmp;
	
	if(is_empty(Q))
	{
		return -1;
	}
	else
	{
		tmp = Q->front;
		Q->front = tmp->next;
		tmp->next = NULL;
	}	
	
	return 0;
}

int is_empty(struct QUEUE *q)
{
	
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
	printf("Enter number of Vertex");
	scanf("%d", &nums);
	if(nums<15)
	{
		g->n_nodes = -1;
		return -1;
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
	int status;
	status = enque(&g->p[e.from], e);
	if(status==-1)
	{
		printf("Error: The edge could not be added\n");
	}
	else
	{
		printf("Node added\n");
	}
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
	printf("Graph is now Cleared ");
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
	if(e.from!=e.to&&g->n_nodes>0&&e.weight>0&&e.from<g->n_nodes&&e.to<g->n_nodes)
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
int bfs(struct GRAPH *g, int start)
{
	queue q;
	q.front = NULL;
	q.rear = NULL;
	
	char *status;
	struct NODE *tmp;
	int curr,i,j;
	
	status = (char *)malloc(sizeof(char) * (g->n_nodes));
	
	for(j=0;j<g->n_nodes;j++)
	{
		status[j]=0;
	}
	
	bfs_enque(&q, start);
	
	while(!queue_is_empty(&q))
	{
		curr = bfs_deque(&q);
		
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
					bfs_enque(&q, i);
					
				}
				tmp = tmp->next;
			}
		}
	}
	return 0;
}
int main()
{
	
	int d,x, ret;
	struct GRAPH *ptr = (struct GRAPH *)malloc(sizeof(struct GRAPH));
	
	ptr->n_nodes = 0;
	
	ret = initialize(ptr);
	if(ret==0)
	{
		while(1)
		{
		printf("\nPlease Choose an operation\n");
		printf("1. Add Edge\n2. Show Edge\n3. Relase Memory\n4. BFS traversal\n0. Exit program\n");
		scanf("%d", &x);
		switch(x)
		{
			case 1:
				helper_add(ptr);
				break;
			case 2:
				disp(ptr);
				break;
			case 3:
				Rel_MEM(ptr);
				break;
			case 4:
				printf("Enter start vertex: ");
				scanf("%d", &d);
				if(d>ptr->n_nodes)
				{
					printf("Invalid Vertex");
				}
				else
				{
					bfs(ptr, d);
				}
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Invalid choice");		
				}
			}
		}
	else
	{
		printf("\nGraph should have minimum 15 nodes\n");
	}
	
	return 0;
	
}
