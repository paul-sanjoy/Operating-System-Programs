/*---   SRTF (preemptive)   ---*/

#include<stdio.h>

typedef struct Process
{
	int a_time;		//arrival time
	int b_time;		//burst time
	int r_time;		//remaining time
	int w_time;		//waiting time
}Process;

int main()
{
	
	int n,i, completedProcesses = 0;	
	int curr_time = 0;
	int next ;
	float total_w_time = 0.0 , avg_w_time =0.0;
	
	/* Inputs */
	printf("Enter number of processes: ");
	scanf("%d", &n);
	
	Process pro[n];
	
	for (i = 0; i < n; i ++)
	{
		printf("Process %d :\n", i + 1);
		
		printf("Enter arrival time : ");
		scanf("%d", &pro[i].a_time);
		
		printf("Enter burst time : ");
		scanf("%d", &pro[i].b_time);
		
		pro[i].r_time = pro[i].b_time;
		pro[i].w_time = 0;
	}
