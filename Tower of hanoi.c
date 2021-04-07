#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void TowerOfHanoi(int ,char ,char ,char );
int main()
{
 int n;
 char frompeg,topeg,auxpeg;
 printf("Enter the number of disks\n");
 scanf("%d",&n);
 if(n<1)
 {
   printf("Error!!! Please enter the correct number of disk\n");
   exit(0);
 }
 printf("Enter the name of frompeg\n");
 scanf(" %c",&frompeg);
 printf("Enter the name of topeg\n");
 scanf(" %c",&topeg);
 printf("Enter the name of auxpeg\n");
 scanf(" %c",&auxpeg);
 system("cls");
 TowerOfHanoi(n,frompeg,topeg,auxpeg);
 return 0;
}
void TowerOfHanoi(int n,char frompeg,char topeg,char auxpeg)
{
 if(n==1)
 {
  printf("move disk 1 from peg %c to peg %c\n",frompeg,topeg);
  return ;
 }
 TowerOfHanoi(n-1,frompeg,auxpeg,topeg);
 printf("Move disk %d from peg %c to peg %c\n",n,frompeg,topeg);
 TowerOfHanoi(n-1,auxpeg,topeg,frompeg);
}
 