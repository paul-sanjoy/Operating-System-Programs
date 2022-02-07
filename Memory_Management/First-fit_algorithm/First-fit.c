/* First-fit algorithm */

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
	int nb,i,np,j ;
	
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
	
	/*First fit algorithm with output*/
	printf("\n\nAllocation is done using first fit algorithm:");
	printf("\nProcess Id \tMemory Block Id \t  Used Memory \t\tUnused Memory");
	for(i=0;i<np;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(blck[j].unused >= proc[i].size)
			{
				blck[j].unused -= proc[i].size; //unused memory after process allocation
				blck[j].used += proc[i].size; //used memory after process allocation
				proc[i].allocated = 1;
				
				printf("\n  %d\t\t\t%d\t\t\t%d\t\t\t%d",proc[i].id,blck[j].id,blck[j].used,blck[j].unused);
				break;
			}
			
		}
		
		if(proc[i].allocated == 0)
		{
			printf("\n%d is not allocated",proc[i].id);
		}
	}
	
	return 0;
	
}
