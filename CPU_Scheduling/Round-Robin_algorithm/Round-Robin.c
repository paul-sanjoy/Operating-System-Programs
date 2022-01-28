/*---   Round-Robin   ---*/

#include<stdio.h>

typedef struct Process
{
	int a_time;
	int b_time;
	int r_time;
}Process;

int main()
{	
	int n,i,k, quantum, completedProcesses = 0;
	int curr_time = 0 , next, prev = -1;
	
	/* Input */
	printf("Enter number of processes : ");
	scanf("%d", &n);
	
	printf("Enter time quantum value : ");
	scanf("%d", &quantum);
	
	Process pro[n];
	
	for (i = 0; i < n; i ++)
	{
		printf("Process id %d :\n", i + 1);
		
		printf("Enter arrival time : ");
		scanf("%d", &pro[i].a_time);
		
		printf("Enter burst time : ");
		scanf("%d", &pro[i].b_time);
		
		pro[i].r_time = pro[i].b_time;
	}
