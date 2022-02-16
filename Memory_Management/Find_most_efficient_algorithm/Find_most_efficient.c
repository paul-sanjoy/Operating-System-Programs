

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



