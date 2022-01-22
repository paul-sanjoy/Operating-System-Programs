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
	
	/* Calculation and gnatt chart */
	printf("\nGantt chart :\n");
	
	while (completedProcesses < n)
	{
		next = 0;
		for (i = 0; i < n; i ++)
		{
			//selecting the next job
			if ((pro[next].r_time > pro[i].r_time) && (pro[i].r_time > 0) && (pro[i].a_time <= curr_time))
			{
				next = i;
			}
		}
		
		//each job perform for one unit of time
		curr_time ++;
		
		//Print the gantt chart
		printf("process %d: (%d-%d);\t", next+1, curr_time - 1, curr_time);
		
		//for the processes that are arived and waiting
		for (i = 0; i < n; i ++)
		{
			if (i != next && pro[i].a_time < curr_time && pro[i].r_time > 0)
			{
				pro[i].w_time ++;
			}			
		}
				
		pro[next].r_time --;   //after performing the job's remaining time decreases 1 unit
		
		// if a job has no remaining time then it is completed
		if (pro[next].r_time <= 0)
		{
			completedProcesses ++; // no. of completed job increases
		}
		
	}
