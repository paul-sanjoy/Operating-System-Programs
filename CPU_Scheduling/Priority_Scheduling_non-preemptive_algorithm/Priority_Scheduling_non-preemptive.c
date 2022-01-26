/*--- Priority Scheduling (non-preemptive) ---*/

#include<stdio.h>

int main()
{
	int n;
	printf("Enter the number of process:");
	scanf("%d",&n);
	
	int i,j,temp, id[n], b_time[n], w_time[n], priority[n] , ta_time[n], pos ;
	float sum_ta_time=0, avg_tat=0;
	
	/*take inputs*/ 
	for(i=0; i<n; i++)
    {
        printf("Process %d :\n", i + 1);
        id[i] = i+1;
        printf("Enter Priority: ");
        scanf("%d", &priority[i]);
        printf("Enter Burst Time : ");
        scanf("%d", &b_time[i]);
        
    }
    
    /* Sorting according to priority */
    for(i=0;i<n;i++)
    {
    	pos = i;
    	for(j=i+1;j<n;j++)
    	{
    		if(priority[j]<priority[pos])
    			pos=j;
		}
		temp = priority[i];
		priority[i] = priority[pos];
		priority[pos]= temp;
		
		//sorting burst time w.r.t priority
		temp = b_time[i];
		b_time[i] = b_time[pos];
		b_time[pos]= temp;
		
		//sorting process id w.r.t priority
		temp = id[i];
		id[i] = id[pos];
		id[pos]= temp;
	}
		
		/* Calculating waiting time , turn around time */	
	w_time[0]=0;	//waiting time for 1st process is zero
	for(i=0;i<n;i++)
	{
		w_time[i]=0;
		for(j=0;j<i;j++)
		{
			w_time[i] = w_time[i] + b_time[j];
		}
		ta_time[i] = w_time[i] + b_time[i];
		sum_ta_time = sum_ta_time + ta_time[i];
	}
	
	/* Output the result */	
	printf("\nThe Gantt chart:\n");
	for(i=0;i<n;i++)
	{
		printf("process %d : (%d - %d)\t", id[i] , w_time[i], b_time[i]+w_time[i]);
	}
	
	avg_tat = (sum_ta_time/n);	
	printf("\n\nAverage Turn around Time:\t%f unit",avg_tat);
		
			
	return 0;		
}

