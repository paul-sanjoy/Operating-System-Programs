

/*
Criteria used for finding the most efficient algorithm for a given set of data:
1. least number of not allocated process.
2. least fragmentation.
*/

#include<stdio.h>

//structure for memory block
typedef struct mBlock
{
	int id;
	int unused;
	int used;
}mBlock;

//structure for process
typedef struct Process
{
	int id;
	int size;
	int allocated;
}Process;


/*first fit algorithm*/
int firstFit(mBlock blck[],Process proc[], int nb ,int np,int *num)
{
	int i , j ,totalFrag=0;
	
	for(i=0;i<np;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(blck[j].unused >= proc[i].size)
			{
				blck[j].unused -= proc[i].size; //unused memory after process allocation
				blck[j].used += proc[i].size; //used memory after process allocation
				proc[i].allocated = 1;
				break;
			}
			
		}
		
		if(proc[i].allocated == 0)  //no. of not allocated processes 
		{
			(*num)++ ;
		}
	}
	
	for(i=0; i<=nb;i++ ) //calculate total fragmentation
	{
		if(blck[i].used != 0)
			totalFrag += blck[i].unused;
	}
	
	return totalFrag;
	
}


/* worst fit algorithm*/
int worstFit(mBlock blck[],Process proc[],int nb ,int np,int *num)
{
	int i , j ,totalFrag=0, highest , index;
	
	for(i=0;i<np;i++)
	{
		highest = -1; // to store the highest unused memory
		
		for(j=0;j<nb;j++)
		{
			//determining the highest unused memory which is greater than process size
			if(blck[j].unused >= proc[i].size ) //if unused memory is greater or equal to process size
			{
				//then process can be allocated
				proc[i].allocated = 1;
				
				if(blck[j].unused > highest)
				{
					highest = blck[j].unused; //update highest
					index = j ;		//index denotes the index of highest unused memory block					
				}
			}
			
		}
		
		if(proc[i].allocated == 1)
		{
			blck[index].unused -= proc[i].size; //unused memory after process allocation
			blck[index].used += proc[i].size;   //used memory after process allocation
		}
		else
		{
			(*num)++; //no. of not allocated processes 
		}
	}
	for(i=0; i<=nb;i++ ) //calculate total fragmentation
	{
		if(blck[i].used != 0)
			totalFrag += blck[i].unused;
	}
	
	return totalFrag;
}


/*best fit algorithm*/
int bestFit(mBlock blck[],Process proc[],int nb ,int np,int *num)
{
	int i , j ,totalFrag=0, lowest , index;
	
	for(i=0;i<np;i++)
	{
		lowest = 99999; // to store the lowest unused memory
		
		for(j=0;j<nb;j++)
		{
			//determining the lowest unused memory which is greater than process size
			if(blck[j].unused >= proc[i].size ) //if unused memory is greater or equal to process size
			{
				//then process can be allocated
				proc[i].allocated = 1;
				
				if(blck[j].unused < lowest)
				{
					lowest = blck[j].unused; //update lowest
					index = j ;		//index denotes the index of lowest unused memory block					
				}
			}
			
		}
		
		if(proc[i].allocated == 1)
		{
			blck[index].unused -= proc[i].size; //unused memory after process allocation
			blck[index].used += proc[i].size;   //used memory after process allocation
		}
		else
		{
			(*num)++; //no. of not allocated processes 
		}
	}
	for(i=0; i<=nb;i++ ) //calculate total fragmentation
	{
		if(blck[i].used != 0)
			totalFrag += blck[i].unused;
	}
	
	return totalFrag;
	
}


/*showing the total fragmentation nad no. of not allocated processes of each algorithm*/
void showChart(int totalFrag1, int totalFrag2, int totalFrag3,int num1,int num2,int num3)
{
	printf("\nWith this data set:- ");
	printf("\n\nFor first fit: ");
	printf("\tno. of processes that are not allocated: %d,\tTotal Fragmentation: %d",num1,totalFrag1);
	printf("\n\nFor worst fit: ");
	printf("\tno. of processes that are not allocated: %d,\tTotal Fragmentation: %d",num2,totalFrag2);
	printf("\n\nFor best fit: ");
	printf("\tno. of processes that are not allocated: %d,\tTotal Fragmentation: %d",num3,totalFrag3);
}



