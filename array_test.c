#include<stdio.h>


//double test[1000][1000];

int main()
{
	double test[1000][1000];
	test[999][999] = 5;
	for(i=0;i<1000)
	printf("%d", test[999][999]);
	return 0;
}
