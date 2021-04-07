#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
typedef struct Node Node;

struct Queue{
	Node *front, *rear;
};
typedef struct Queue Queue;

int isEmpty(Queue *q){
	return (q->rear == NULL || q->front == NULL);
}

int enqueue(Queue *q, int d){
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	
	if(temp == NULL){
		return -1;
	}
	
	temp->data = d;
	temp->next = NULL;
	
	if(isEmpty(q)){
		q->front = temp;
	}
	else{
		q->rear->next = temp;
	}
	
	q->rear = temp;
	return temp->data;
}

int dequeue(Queue *q){
	Node *temp;
	int data;
	
	if(isEmpty(q)){
		
		return -1;
	}
	
	temp = q->front;
	data = temp->data;
	q->front = q->front->next;
	free(temp);
	return data;
}

int display(struct Queue *q){
	Node *temp;
	
	if(isEmpty(q)){
		printf("Queue is empty.\n");
		return -1;
	}
	
	temp = q->front;
	
	printf("Queue is: ");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return 0;
}

int main(){
	Queue q;
	q.front = NULL;
	q.rear = NULL;
	
	int choice,data,status;
	
	while(1){
		printf("\n1 Enqueue\n");
		printf("2 Dequeue\n");
		printf("3 Display Queue\n");
		printf("4 Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: printf("Enter the data to enqueue: ");
					scanf("%d", &data);
					status = enqueue(&q, data);
					if(status == -1){
						printf("Memory not available.\n");
						break;
					}
					printf("Data enqueued: %d\n", status);
					break;
			case 2: status = dequeue(&q);
					if(status == -1){
						printf("Cannot dequeue, no data.\n");
						break;
					}
					printf("Data dequeued: %d\n", status);
					break;
			case 3: display(&q);
					break;
			case 4: exit(0);
					break;
			default: printf("Invalid choice.\n");
					break;
		}
	}
	return 0;
}
