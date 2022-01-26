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
		
	
