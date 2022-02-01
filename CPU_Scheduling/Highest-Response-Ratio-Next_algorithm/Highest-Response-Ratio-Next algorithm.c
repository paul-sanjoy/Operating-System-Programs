/*---   Highest-Response-Ratio-Next algorithm   ---*/

#include<stdio.h>
//structure for process
typedef struct Process
{
	int id;
	int b_time;
	int a_time;
	int ta_time;
	int completed ;
}Process;

int main()
{
	int n, i , k= -1 , num, pos ,sumOfBtime=0, current_time =0 ; //current_time will increase with current serviced process
	
	printf("Enter the number of process: ");
	
	scanf("%d",&n);
	
	Process pro[n];
	
	/* Inputs */	
	for (i = 0; i < n; i ++)
	{
		pro[i].id = i+1;
		
		printf("Process id %d :\n", i + 1);
		
		printf("Enter arrival time : ");
		scanf("%d", &pro[i].a_time);
		
		printf("Enter burst time : ");
		scanf("%d", &pro[i].b_time);
		
		pro[i].completed = 0; //zero means not completed
		
		sumOfBtime += pro[i].b_time; //sum of all burst time
	}
		
	
	
