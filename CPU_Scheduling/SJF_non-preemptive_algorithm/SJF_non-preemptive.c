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

void timeCalculations(int n, int p_details[][6])
{
    int index ,i , j, k, temp;
    int prevCompTime;	//to store the completion time of previous process
    int currBurstTime;	//to store the minimum burst time of any process whose arrival time is less than or equal to prevCompTime 
    
	/* for the 1st process */ 
    p_details[0][3] = p_details[0][1] + p_details[0][2]; //completion time = arrival time + burst time
    p_details[0][5] = p_details[0][3] - p_details[0][1]; //turn around time = completion time - arrival time
    p_details[0][4] = p_details[0][5] - p_details[0][2]; //waiting time = turn around time - burst time
    
	/* from 2nd process onwards */ 
    for( i=1; i<n; i++)
    {
        prevCompTime = p_details[i-1][3]; 
        currBurstTime = p_details[i][2];
        for(j=i; j<n; j++)
        {
        	//if arrival time of jth process is less or equal to prev Completion Time
        	//and burst time of jth process is less or equal to current Burst Time 
            if(prevCompTime >= p_details[j][1] && currBurstTime >= p_details[j][2])
            {
                currBurstTime = p_details[j][2]; //update current burst time
                index = j;
            }
        }
        //now for 'index'th process--
        p_details[index][3] = prevCompTime + p_details[index][2];	//completion time = arrival time + burst time
        p_details[index][5] = p_details[index][3] - p_details[index][1];	//turn around time = completion time - arrival time
        p_details[index][4] = p_details[index][5] - p_details[index][2];	//waiting time = turn around time - burst time
        
        //swapping all 6 process details of 'index'th process with ith process--
        for(k=0; k<6; k++)
        {
            temp = p_details[index][k];		
            p_details[index][k] = p_details[i][k];
            p_details[i][k] = temp;
        }
    }
}

int main()
{
    int n, i ;
    
	/* take input*/
    printf("Enter the number of Processes : ");
    scanf("%d", &n);
     
    for(i=0; i<n; i++)
    {
        printf("Process %d :\n", i + 1);
        p_details[i][0] = i;
        printf("Enter Arrival Time : ");
        scanf("%d", &p_details[i][1]);
        printf("Enter Burst Time : ");
        scanf("%d", &p_details[i][2]);
    }
    
    /*operations*/
    sortArrivalTime(n, p_details);
    timeCalculations(n, p_details);
    
    /*print output*/
    printf("\nGantt chart :\n\n");
    for (i = 0; i < n; i ++)
    {
    	printf("process %d : (%d - %d) \n", p_details[i][0] + 1, p_details[i][1] + p_details[i][4], p_details[i][1] + p_details[i][4] + p_details[i][2]);
    }
    
    printf("\n\n");
    
    for(i=0; i<n; i++)
    {
        printf("Waiting time of process %d : %d unit\n", p_details[i][0] + 1, p_details[i][4]);
    }
    
    return 0;
}

