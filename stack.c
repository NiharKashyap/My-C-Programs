#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack{

    int value;
    struct stack *next;
};

struct stack *tos;

int show()
{
	struct stack * tmp;
	
	tmp = tos;
	
	while(tmp!=NULL)
	{
		printf("%d", tmp->value);
		tmp = tmp->next;
	}
	return 0;
}

int main()
{
    struct stack * tmp;
    int choice;
    do
    {
    tmp = (struct stack*)malloc(sizeof(struct stack));
    tmp->next=NULL;
    printf("Enter Data");
    scanf("%d",&tmp->value);
    if(tos==NULL)
    {
        tos=tmp;
    }
    else
    {
        tmp->next=tos;
        tos = tmp;
    }
    printf("%d", tos->value);   
    printf("Enter 0 to exit other to continue\n");
    scanf("%d", &choice);
    }
    while(choice!=0);
    show();
    return 0;
    
}
