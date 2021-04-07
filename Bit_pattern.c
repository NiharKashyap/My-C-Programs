#include<stdio.h>
#include<stdlib.h>


void bin(unsigned int n) 
{ 
    unsigned i;
	 
    for (i = 1 << 3; i > 0; i = i / 2) 
        (n & i)? printf("1"): printf("0"); 
}  

int main()
{
	
	int HH, mm, DD, MM, YY,i,hour, minute, day, month, year;
	unsigned int total;

	printf("Enter hours");
	scanf("%d", &HH);
	
	if((HH>23) || (HH<0))
	{
		printf("Invalid input");
		return 0;
	
	}
	printf("Enter minutes");
	scanf("%d", &mm);
	if((mm>59) || (mm<1))
	{
		printf("Invalid input");
		return 0;
	
	}
	printf("Enter Day");
	scanf("%d", &DD);
	if((DD>31) || (DD<1))
	{
		printf("Invalid input");
		return 0;
	
	}
	printf("Enter month");
	scanf("%d", &MM);
	if((MM>12) || (MM<1))
	{
		printf("Invalid input");
		return 0;
	
	}
	printf("Enter year");
	scanf("%d", &YY);
	if((YY>3999) || (YY<1))
	{
		printf("Invalid input");
		return 0;
	}
	
	//Time converted to minutes and added in a single variable
	
	total = (HH*60) + mm + ((DD-1)*1440) + ((MM-1)*44640) + ((YY-1)*535680);
	
	//Calculations to get back original time from total variable
	
	year = total/535680 + 1;
	month = (total - (year-1)*535680)/44640 + 1;
	day = (total - (year-1)*535680 - (month-1)*44640)/1440 + 1;
	hour = (total - (year-1)*535680 - (month-1)*44640 - (day-1)*1440)/60;
	minute = (total - (year-1)*535680 - (month-1)*44640 - (day-1)*1440-hour*60);

	printf("\nRepresentation of time and date in single variable: %d\n", total);
	
	printf("\nOriginal time and date entered by user: ");
	printf("\nHour: %d", hour);
	printf("\nMinute: %d", minute);
	printf("\nDay: %d", day);
	printf("\nMonth: %d", month);
	printf("\nYear: %d", year);
	
	
	printf("\nSize of variable: %d bits\n", sizeof(total)*8);
	printf("\nBit Pattern: ");
	bin(3);	
	getch();
	return 0;
}
//Nihar Kashyap, CSM20005
