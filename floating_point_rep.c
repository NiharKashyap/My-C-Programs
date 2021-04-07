#include<stdio.h>
int main()
{
	
	int a, *ptr;
	float f;
	
	printf("One integer");
	scanf("%d", &a);
	f = a + 1.675;
	ptr = &a;
	printf("%d\n", *ptr);
	
	ptr = (int *)&f;
	printf("%d\n", *ptr);
	return 0;
	
}
