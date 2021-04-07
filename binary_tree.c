#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
}; 
struct node *create();
void insert(struct node *,struct node *);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
 
int main()
{
    char ch;
    struct node *root=NULL,*temp;
    
    do
    {
        temp=create();
        if(root==NULL)
            root=temp;
        else    
            insert(root,temp);
            
        printf("\nDo you want to enter more(y/n)?");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    system("cls");
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    inorder(root);
    getch();
    return 0;
}
 
struct node *create()
{
    struct node *temp;
    printf("\nEnter data:");
    temp=(struct node*)malloc(sizeof(struct node));
    fflush(stdin);
    scanf("%d",&temp->data);
    temp->left=temp->right=NULL;
    return temp;
}
 
void insert(struct node *root,struct node *temp)
{   if(temp->data==root->data)
    {
    	printf("Duplicate value not allowed");
    	return;
				}
    if(temp->data<root->data)
    {
        if(root->left!=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }
    
    if(temp->data>root->data)
    {
        if(root->right!=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}
//preorder 
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//inorder
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
		inorder(root->right);
    }
}
//postorder
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
	    postorder(root->right);
	    printf("%d ",root->data);
    }
}

