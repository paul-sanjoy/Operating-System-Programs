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
	
	/* Calculating and printing gantt chart */
	printf("\nGantt chart :\n");
	
	curr_time = pro[0].a_time;
	
	for (i = 1; i < n; i ++)
	{
		if (curr_time > pro[i].a_time)
		{
			curr_time = pro[i].a_time;
		}
	}
	
		while (completedProcesses < n)
	{
		//maintain and select from queue
		k = prev;
		next = 0;
		while (1)
		{
			k = (k + 1) % n;
			if (pro[k].a_time <= curr_time && pro[k].r_time > 0)
			{
				next = k;
				break;
			}
		}
		
		if (pro[next].r_time <= quantum) //if remaining time is less than time quantum
		{
			printf("process %d: (%d-%d);\t", next + 1, curr_time, curr_time + pro[next].r_time);
			curr_time += pro[next].r_time;
			pro[next].r_time = 0;
			completedProcesses ++;
		}
		else  //if remaining time is greater than time quantum
		{
			
			printf("process %d: (%d-%d);\t", next + 1, curr_time, curr_time + quantum);
			curr_time += quantum;
			pro[next].r_time -= quantum;
		}
		
		prev = next;
	}
	
	return 0 ;
}

