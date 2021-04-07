#include<stdio.h>

int lim_2;
int first[10], second[10];
int lim_1;

int main()

{
	
	int i;
	printf("%d %d", lim_1,lim_2);
	printf("Elements in first array");
	scanf("%d", &lim_1);
	printf("Elements in second array");
	scanf("%d", &lim_2);
	printf("%d %d", lim_1,lim_2);
	printf("Entering on first array:\n");
	
	for(i=0;i<lim_1;i++)
	{
		scanf("%d", &first[i]);
	}	
	printf("\nEntering on second array:\n");
	
	for(i=0;i<lim_2;i++)
	{
		scanf("%d", &second[i]);
	}
	//printf("%d",sizeof(first));
		
	printf("\n");
	printf("Printing first array:\n");
	for(i=0;i<lim_1;i++)
	{
		printf("%d", first[i]);
		printf("\t");
	}
	printf("\nPrinting second array:\n");
	for(i=0;i<lim_2;i++)
	{
		printf("%d", second[i]);
		printf("\t");
	}
	
	return 0;
}
