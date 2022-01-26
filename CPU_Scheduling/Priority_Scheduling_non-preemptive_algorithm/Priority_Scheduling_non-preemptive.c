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
