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
			
	/* Calculation and printing Gantt Chart*/
	printf("\n");
	printf("\nGantt Chart: \n");
	for(current_time = pro[0].a_time; current_time < sumOfBtime ;) //iterate untill all process completed
	{
		float highest_ratio = -1 , temp_ratio;
		
		for(i =0; i<n; i++)
		{
			if(pro[i].completed == 0 && pro[i].a_time <= current_time) //if the process is not completed and has arrived
			{
				temp_ratio = (pro[i].b_time + current_time - pro[i].a_time)/pro[i].b_time ; //ratio = (burst time + waiting time)/burst time 
				
				if(highest_ratio < temp_ratio) //to know the highest ratio among all calculated ratios
				{
					highest_ratio = temp_ratio; 
					
					pos = i; //index of process with highest response ratio
				}
				
			}
		}
		printf("process %d: (%d - %d);\t",pro[pos].id,current_time,(current_time + pro[pos].b_time));
		
		current_time += pro[pos].b_time ; //current time is updated with current serviced process' burst time
		
		pro[pos].completed =1; //denotes the process with hrr is serviced
		
		pro[pos].ta_time = current_time - pro[pos].a_time ;
		
	}
	
	/*print turn around time*/
	printf("\n\nProcess \tTurn around time");
	for(i=0;i<n;i++)
	{
		printf("\n  %d  \t\t\t%d",pro[i].id,pro[i].ta_time);
	}
	
	return 0;
}

