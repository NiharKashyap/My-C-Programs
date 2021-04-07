// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main()
{
  char s[1000], n[10] = {'0','1','2','3','4','5','6','7','8','9'};
  int i, j, count = 0;
  scanf("%[^\n]%*c", s);
  for (i = 0; i < strlen(n) - 1; i++)
  {
	for (j = 0; j < strlen(s); j++)
    {
    	if(n[i] == s[j]){
    		count++;
		}
    }
    printf("%d ", count);
    count = 0;
  }
  return 0;
}
