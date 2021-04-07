#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct room
{
	char name[20];
	int age;
	int arrival_d,arrival_m,arrival_y;
	int departure_d,departure_m,departure_y;
	char coming[20];
	char going[20];
	int flag;
	int room_no;
	struct room* next;
}room;

struct room *start,*last, arr[500];

int patient_count = 0;

int insert()
{
	struct room *tmp;
	int i_room;
	printf("Enter room number to be Alloted\n");
	scanf("%d", &i_room);
	
	tmp = start;
	
	while(tmp!=NULL)
	{
		if(tmp->room_no==i_room)
		{
			if(tmp->flag==1)
			{
			printf("Room Occupied. Please select a different room or discharge this person first\n");
			return;
			}
			printf("Enter name\n");
			scanf("%s", &tmp->name);
			printf("Enter age\n");
			scanf("%d", &tmp->age);
			printf("Enter arrival state\n");
			scanf("%s", &tmp->coming);
			printf("Enter departure state\n");
			scanf("%s", &tmp->going);
			printf("Enter arrival date (format dd/mm/yy)\n");
			scanf("%d%d%d", &tmp->arrival_d,&tmp->arrival_m,&tmp->arrival_y);
			printf("Enter departure date (format dd/mm/yy)\n");
			scanf("%d%d%d", &tmp->departure_d,&tmp->departure_m,&tmp->departure_y);
			tmp->flag=1;
			patient_count+=1;
			return;
		}
		tmp = tmp->next;
	}
	printf("Room not found\n");
	return 0;
}
int vacate()
{
	struct room *tmp;
	tmp = start;
	int i_room;
	char person[20];
	printf("Enter name and room number of person to discharge: ");
	scanf("%s%d", &person, &i_room);
	
	while(tmp!=NULL)
	{
		if((strcmp(tmp->name,person)==0)&&(tmp->room_no==i_room))
		{
			tmp->flag=0;
			printf("Discharged. \n");
			patient_count=patient_count-1;
			return;
		}
		tmp = tmp->next;
	}
	printf("Person not found\n");

	return 0;
}
int showOccupied()
{
	struct room *tmp;
	tmp = start;
	
	if(patient_count==0)
	{
		printf("List is empty\n");
	}
	while(tmp!=NULL)
	{
		if(tmp->flag==1)
		{
		printf("Name: %s\n", tmp->name);
		printf("Age: %d\n", tmp->age);
		printf("Coming from: %s\n", tmp->coming);
		printf("Going to: %s\n", tmp->going);
		printf("Arrived on: %d/%d/%d\n", tmp->arrival_d,tmp->arrival_m,tmp->arrival_y);
		printf("Departed on: %d/%d/%d\n", tmp->departure_d,tmp->departure_m,tmp->departure_y);
		printf("Room Number: %d\n", tmp->room_no);
		}
		tmp = tmp->next;
	}
	return 0;
}
int search()
{
	int i_room;
	char person[20];
	printf("Enter name and room number of person to search: ");
	scanf("%s%d", &person, &i_room);

	struct room *tmp;
	tmp = start;

	while(tmp!=NULL)
	{
		if((strcmp(tmp->name,person)==0)&&(tmp->room_no==i_room))
		{
			printf("Details of person %s ......\n", person);
			printf("Name: %s\n", tmp->name);
			printf("Age: %d\n", tmp->age);
			printf("Coming from: %s\n", tmp->coming);
			printf("Going to: %s\n", tmp->going);
			printf("Arrived on: %d/%d/%d\n", tmp->arrival_d,tmp->arrival_m,tmp->arrival_y);
			printf("Departed on: %d/%d/%d\n", tmp->departure_d,tmp->departure_m,tmp->departure_y);
			printf("Room Number: %d\n", tmp->room_no);
			return;
		}
		tmp = tmp->next;
	}
	printf("Person not found\n");
	return 0;

}
int peopleSearch()
{
	int i_room, index;
	char person[20];
	struct room *loc;
	printf("Enter name and room number of person to search: ");
	scanf("%s%d", &person, &i_room);
	index = i_room-89;
	
	//tmp = start;
	loc = binarySearch(arr,0, 500, index);
	//while(tmp!=NULL)
	//{
	//	if((strcmp(tmp->name,person)==0)&&(tmp->room_no==i_room))
	//	{
	printf("Roo is %d", loc->room_no);
	if((loc!=NULL)&&(loc!=-1))
	{
			printf("Details of person %s ......\n", person);
			printf("Name: %s\n", loc->name);
			printf("Age: %d\n", loc->age);
			printf("Coming from: %s\n", loc->coming);
			printf("Going to: %s\n", loc->going);
			printf("Arrived on: %d/%d/%d\n", loc->arrival_d,loc->arrival_m,loc->arrival_y);
			printf("Departed on: %d/%d/%d\n", loc->departure_d,loc->departure_m,loc->departure_y);
			printf("Room Number: %d\n", loc->room_no);
			return;
	}
	//	}
	//	tmp = tmp->next;
	//}
	printf("Person not found\n");
	return 0;
}

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) 
	{ 
        int mid = (l + r)/ 2;
  
        // If the element is present at the middle 
        // itself 
        if (mid == x) 
            return arr[mid]; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (mid > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1;
}
int showVacant()
{
	struct room *tmp;
	tmp=start;
	printf("List of vacant rooms: ");
	while(tmp!=NULL)
	{
		if(tmp->flag==0)
		{
			printf("%d ,", tmp->room_no);
		}
		tmp = tmp->next;
	}
	return 0;
}
int main()
{
	struct room *new_room, *tmp;
	int x,c,i;
	for(i=89;i<=411;i++)
	{
		new_room = (struct room*)malloc(sizeof(struct room));
		new_room->next=NULL;
		new_room->room_no=i;
		new_room->flag=0;
		//arr[i-89]=new_room;
		if (start==NULL)
		{
		start = new_room;
		last = new_room;
		}
		else
		{
		last->next=new_room;
		last = new_room;
		}
	}
	do
	{
		printf("Choose...\n1 to insert\n2 to vacate\n3 to show occupied rooms\n4 to search\n5 to show empty rooms\n0 to exit.\n");
		scanf("%d", &x);
		switch(x)
		{
		 case(1): insert();
		 break;
		 case(2): vacate();
		 break;
		 case(3): showOccupied();
		 break;
		 case(4): search();
		 break;
		 case(5):showVacant();
		 break;
		 case(0): exit(0);
		 break;
		 default:printf("Invalid choice\n");
		 return 0;
		}
		printf("\nPress 0 to exit any other number to repeat\n");
		scanf("%d", &c);
	}
	while(c!=0);
	getch();
	return 0;
}

