/*---   SJF (non-preemptive)   ---*/

#include<stdio.h>

int p_details[20][6];

/* p_details[i][0] stores process id , p_details[i][1] stores arrival time, p_details[i][2] stores burst time, 
   p_details[i][3] stores completion time, p_details[i][4] stores waiting time and p_details[i][5] stores turn around time
   of ith process 
*/
 
/* Sort process-details in increasing order of arrival time */
void sortArrivalTime(int n, int p_details[][6])
{
	int temp , i , j ,k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(p_details[j][1] > p_details[j+1][1])
            {
            	//all 6 process-details of j process has to swap with j+1 process
                for(k=0; k<5; k++)
                {
                    temp = p_details[j][k];
                    p_details[j][k] = p_details[j+1][k];
                    p_details[j + 1][k] = temp;
                }
            }
        }
    }
}
