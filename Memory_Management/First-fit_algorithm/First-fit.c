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
	
