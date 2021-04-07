#include <stdio.h>
#include<stdlib.h>
int main() 
{
    
    int n=5, *ptr,i;
    ptr = (int *)malloc(sizeof(int)*n);
    printf("Enter data\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", ptr+i);
    }
    printf("\nEntered data\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", *ptr+i);
    }
    
    return 0;
}
