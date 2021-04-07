#include<stdio.h>
#include<malloc.h>

#define Info_type int
typedef struct B_Node
{
	Info_type key;
}B_Node;

typedef struct node
{
	B_Node *info;
	struct node *left;
	struct node *right;
}NODE;

typedef struct stack_node
{
	NODE *D;
	struct stack_node *next;
}stack_node;

typedef struct stack
{
	stack_node *tos;
}STACK;

int push(STACK *s, NODE *d)
{
	stack_node *nde = malloc(sizeof(stack_node));
	nde->D= d;
	nde->next = NULL;
	if(s->tos==NULL)
	{
		s->tos = nde;
	}
	else
	{
		nde->next = s->tos;	
		s->tos = nde; 
	}
	return 0;
}
NODE* pop(STACK *s)
{
	stack_node *d = s->tos;
	s->tos = s->tos->next;
	//printf("--Popped %d --\n", d->D->info);
	//printf("%d ", d->D->info);
	return d->D; 
}

int is_empty(STACK *s)
{
	if (s->tos==NULL)
		return 1;
	
	return 0;
}

int explore(NODE *n)
{
	printf("%d ",n->info->key);
	return 0;
}

int display(STACK *s)
{	
	stack_node *tmp = s->tos;
	printf("\nCurrent stack\n");
	while(tmp!=NULL)
	{
		printf("%d ", tmp->D->info);
		tmp = tmp->next;
	}
	return 0;
}

int preorder(NODE *root)
{
	STACK s;
	s.tos=NULL;
	NODE *curr;
	if(root==NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	else
	{
		push(&s, root);
		while(!is_empty(&s))
		{
			curr = pop(&s);
			explore(curr);
			if(curr->right!=NULL)
			{
				//printf("\nPushed %d from right of %d\n", curr->right->info->key, curr->info->key);
				push(&s,curr->right);
				//display(&s);
			}
			if(curr->left!=NULL)
			{
				//printf("\nPushed %d from left of %d\n", curr->left->info->key, curr->info->key);
				push(&s,curr->left);
				//display(&s);
			}	
		}
	}
	return 0;
}

int postorder(NODE *root)
{
	STACK S;
	S.tos = NULL;
	
	NODE *tmp = root;
	NODE *curr;
	
	push(&S, tmp);
	
	while(!is_empty(&S))
	{
		//tmp = pop(&S);
		while(tmp!=NULL)
		{
			push(&S, tmp->right);
			printf("Pushed %d\n", tmp->right->info);
			push(&S, tmp);
			printf("Pushed %d\n", tmp->info);
			tmp = tmp->left;
		}
		tmp = pop(&S);
		printf("Popped %d\n", tmp->info);
		if(tmp->right && tmp->right==S.tos->D)
		{
			pop(&S);
			printf("popped %d\n", tmp->right->info);
			push(&S, tmp);
			printf("Pushed %d\n", tmp->info);
			tmp = tmp->right;
		}
		else
		{
			printf("%d ", tmp->info);
			tmp = NULL;
		}
	}
	/*
	do
    { 
        while(tmp) 
        { 
            if (tmp->right) 
                push(&S, tmp->right); 
                
            push(&S, tmp); 
            tmp = tmp->left; 
        } 
        tmp = pop(&S); 
 
        if (tmp->right && S.tos->D == tmp->right) 
        { 
            pop(&S); 
            push(&S, tmp); 
            tmp = tmp->right; 
        } 
        else 
        { 
            printf("%d ", tmp->info); 
            tmp = NULL; 
        } 
    } while (!is_empty(&S)); 
    */
	return 0;
	
}
int insert(NODE *root, Info_type data)
{
	
	B_Node* node=(B_Node*)malloc(sizeof(B_Node));
	
	node->key = data;
	
	if(root->info==NULL)
	{
		
		root->info = node;
		root->left = NULL;
		root->right= NULL;
		
		printf("Added %d at root\n", data);
	}
	else
	{
		NODE *temp =(NODE*)malloc(sizeof(NODE));
	
		temp->info = node;
		temp->left=NULL;
		temp->right=NULL;
		
		NODE *curr;
		curr = root;
		while(1)
		{
			if(data<curr->info->key)
			{
				printf("Went left\n");
				if(curr->left==NULL)
				{
					curr->left = temp;
					printf("Added %d left of %d\n\n", curr->left->info->key, curr->info->key);
					break;
				}
				else
				{
					curr = curr->left;
				}
			}
			else
			{
				printf("Went right\n");
				if(curr->right==NULL)
				{
					
					curr->right = temp;
					printf("Added %d right of %d \n\n", curr->right->info->key, curr->info->key);
					break;
				}
				else
				{
					curr = curr->right;
				}
			}
		}
		
	}
	return 0;
}

void search(NODE *root, int data)
{
	NODE *tmp = root;
	
	while(tmp!=NULL)
	{
		if(data>tmp->info->key)
		{
			tmp = tmp->right;
		}
		else if(data<tmp->info->key)
		{
			tmp = tmp->left;
		}
		else if(data==tmp->info->key)
		{
			printf("Found it");
			return;
		}
	}
	printf("Not found");
}

int del(NODE **root, Info_type data)
{
	NODE *par, *Suc, *P_Suc, *del;
	Info_type deleted;
	if(root == NULL)
	{
		printf("Empty");
		return;
	}
	else
	{
		par = NULL;
		del = *root;
		while(del!=NULL)
		{	
			//Traverse to node
			if(data == del->info->key)
			{
				//Node has no child
				if(del->left==NULL && del->right==NULL)
				{
					if(par==NULL)
					{
						printf("Deleted %d ",del->info->key);
						free(del);
						//free(root);
						*root = NULL;
						break;
					}
					else if(par->right==del)
					{
						par->right=NULL;
						printf("Deleted %d",del->info->key );
						free(del);
						break;
					}
					else if(par->left==del)
					{
						par->left=NULL;
						printf("Deleted %d",del->info->key );
						free(del);
						break;
					}
				}
				//Node has both child
				else if(del->left!=NULL && del->right!=NULL)
				{
					
					P_Suc = del;
					Suc = del->right;
					
					while(Suc->left!=NULL)
					{
						P_Suc = Suc;
						Suc = Suc->left;
					}
					
					Suc->left = del->left;
					
					if(del!=P_Suc)
					{
						P_Suc->left = Suc->right;
					}
					
					if(par==NULL)
					{
						if(del->right!=Suc)
							Suc->right = del->right;
						*root = Suc;
					}
					else
					{
						if(data<par->info->key)
						{
							par->left= Suc;
						}
						else
						{
							par->right = Suc;
						}
					}
					break;
				}
				//Node has only right child
				else if(del->left==NULL)
				{
					if(par==NULL)
					{	
						*root = del->right;
					}
					else if(par->left==del)
					{
						par->left = del->right;
					}
					else
					{
						par->right = del->right;	
					}
					printf("Deleted %d\n",del->info->key);
					free(del);
					break;
				}
				//node has only left child
				else if(del->right==NULL)
				{
					if(par==NULL)
					{	
						*root = del->left;
					}
					else if(par->left==del)
					{
						par->left = del->left;
					}
					else
					{
						par->right = del->left;	
					}
					del->left = NULL;
					printf("Deleted %d\n",del->info->key);
					free(del);
					break;
				}
			}
			else if(data>del->info->key)
			{
				par = del;
				del = del->right;
			}
			else if(data<del->info->key)
			{
				par = del;
				del = del->left;
			}
		}
	}
	return 0;
}

int main()
{
	
	NODE *root=(NODE*)malloc(sizeof(NODE));
	root->info = NULL;
	root->left=NULL;
	root->right=NULL;
	
	insert(root, 1);
	insert(root, 6);
	insert(root, 20);
	insert(root, 18);
	insert(root, 25);
	insert(root, 30);
	insert(root, 16);
	insert(root, 19);
	
	preorder(root);
	del(&root, 6);
	preorder(root);
	
	return 0;
}
