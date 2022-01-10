/*---    First Come First Serve (FCFS) algorithm    ---*/

#include<stdlib.h>
#include<stdio.h>

int main()
{
	int i,n ;
	
	printf("Enter the number of processes:\n");
	scanf("%d", &n);
	
	/*allocating n space for waiting time, burst time and turn around time*/
	int w_time[n], b_time[n], ta_time[n];
	
	for (i = 0; i < n; i++)
	{
		printf("Enter the burst time of process id %d : ", i + 1);  //i+1,as process id starts from 1
		scanf("%d", &b_time[i]);
	}
	
	w_time[0] = 0; 	// Waiting time of 1st process is zero
	ta_time[0] = b_time[0];	 //So turn around time is same as burst time for 1st process
	
	/* From 2nd process waiting times and turn around times are calculated below*/
	for (i = 1; i < n; i ++)
	{
		w_time[i] = w_time[i - 1] + b_time[i - 1];
		ta_time[i] = w_time[i] + b_time[i];
	}
	
	/* The gantt chart*/
	printf("\n Gantt chart :\n");
	for (i = 0; i < n; i ++)
	{
		printf("\tprocess id %d : (%d - %d)\t", i + 1, w_time[i], w_time[i] + b_time[i]);
	}
	
	/*Printing Turn around time for each processes*/
	printf("\n\n");
	for (i = 0; i < n ; i++)
	{
		printf("\nTurn around time for process id %d is %d", i+1, ta_time[i]);
	}
	
	return 0;
}



