

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

int main()
{
	int nb,i,np,j,lowest,index ;
	
	//Input the memory block partitions:
	printf("Enter the number of memory blocks: ");
	scanf("%d",&nb);
	
	mBlock blck[nb];
	
	printf("Enter the sizes of the memory blocks: ");
	for(i=0; i<nb ; i++)
	{
		blck[i].id = i+1;
		scanf("%d",&(blck[i].unused));
		blck[i].used = 0; //initially used memory is zero
	}
	
	//Input the processes:
	printf("\nEnter the number of processes: ");
	scanf("%d",&np);
	
	Process proc[np];
	
	printf("Enter the sizes of the processes: ");
	for(i=0; i<np ; i++)
	{
		proc[i].id = i+1;
		scanf("%d",&(proc[i].size));
		proc[i].allocated = 0; //initially process is not allocated
	}
	
	/* best fit algorithm with output */
	printf("\n\nAllocation is done using best fit algorithm:");
	printf("\nProcess Id \tMemory Block Id \t  Used Memory \t\tUnused Memory");
	
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
			
			printf("\n  %d\t\t\t%d\t\t\t%d\t\t\t%d",proc[i].id,blck[index].id,blck[index].used,blck[index].unused);
		}
		else
		{
			printf("\nProcess %d is not allocated.",proc[i].id);
		}
	}
	
	return 0;
	
}
