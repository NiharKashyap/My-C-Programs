#include<stdio.h>

#include<malloc.h>

void display(int data[], int n);
typedef struct {
  int start, end;
}
listRange;

struct Node {
  listRange info;
  struct Node * next;
};
listRange empty() {
  listRange r;
  return r;
}

struct Node * createNode(listRange r) 
{
  struct Node * ptr;
  ptr = (struct Node * ) malloc(sizeof(struct Node));
  ptr -> info = r;
  ptr -> next = NULL;
  return ptr;
}
int isEmpty(struct Node * top) 
{
  if (top == NULL)
  {
  	printf("Terminated");
  	return 1;
  }
    
  return 0;
}
void push(struct Node ** top, listRange r) {
  struct Node * ptr = createNode(r);
  if ( * top == NULL) 
  {
    * top = ptr;
  } else 
  {
    ptr -> next = * top;
    * top = ptr;
  }
}
listRange pop(struct Node ** top) {
  if ( * top == NULL) {
    printf("Underflow");
    return empty();
  } else 
  {
    struct Node * ptr = * top;
    * top = ( * top) -> next;
    // free(ptr);
    return ptr -> info;
  }
}
void displayStack(struct Node * top) 
{
  if (top == NULL) 
  {
    return;
  } else 
  {
    printf("\n Stack Display\n");
    struct Node * ptr = top;
    while (ptr != NULL) 
	{
      printf("[%d %d]", ptr -> info.start, ptr -> info.end);
      ptr = ptr -> next;
    }
    printf("\n");
  }
}
int quick(int data[], int count) {
  struct Node * stack = NULL;
  listRange p;
  int l, r, pos, from, to;
  int pivot;
  if (count < 2) return 0;
  p.start = 0;
  p.end = count - 1;
  push( & stack, p);
  //displayStack(stack);
  //printf("=%d=\n",isEmpty(stack));
  while (isEmpty(stack) != 1) {
    p = pop( & stack);
    from = p.start;
    to = p.end;
    l = from;
    r = to;
    pos = from;
    pivot = data[pos];
    while (l < r) 
	{
      while (l < r) 
	  {
        if (data[r] < pivot) 
		{ // here was the errror
          data[pos] = data[r];
          data[r] = pivot;
          pos = r;
          l++;
          break;
        } else 
		{
          r--;
        }
      }
      while (l < r) 
	  {
        if (data[l] >= pivot) 
		{
          data[pos] = data[l];
          data[l] = pivot;
          pos = l;
          r--;
          break;
        } 
		else 
		{
          l++;
        }
      }
    }
    if ((pos + 1) < to) 
	{
      p.start = pos + 1;
      p.end = to;
      push( & stack, p);
    }
    if (from < (pos - 1)) 
	{
      p.start = from;
      p.end = pos - 1;
      push( & stack, p);
    }
  }
  printf("\n Display Array From Quick Func");
  display(data, count);
  return 0;
}
void display(int data[], int n) {
  int i;
  printf("\n Array Display\n");
  for (i = 0; i < n; i++) {
    printf(" %d", data[i]);
  }
  printf("\n");
}
int main() {
  int data[] = {
    134,
    89,
    128,
    129,
    141,
    69,
    83,
    126,
    77,
    105
  };
  int n = 10;
  display(data, n);
  quick(data, n);
  display(data, n);
  return 0;
}
