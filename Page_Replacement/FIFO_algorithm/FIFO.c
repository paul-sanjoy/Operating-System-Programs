/*   FIFO algorithm   */

#include<stdio.h>

//This checks whether the page is already present
int isPresent(int framesTable[], int numFrames, int pg_req )
{
	int i;
	for(i=0; i< numFrames; i++)
	{
		if(framesTable[i] == pg_req)
			return 1;
	}
	
	return 0;	
}

//This prints page frame status
void printTable(int framesTable[], int numFrames)
{
	int i;
	for(i=0; i<numFrames; i++)
	{
		if(framesTable[i] == -1)
			printf("\tempty");
		else
			printf("\t%d",framesTable[i]);	
	}
}


int main()
{
	int i,numFrames, n, numFaults=0 , pos=0;
	
	printf("Enter the number of page frames: ");
	scanf("%d",&numFrames);
	
	int framesTable[numFrames];
	for(i=0;i<numFrames;i++)
	{
		framesTable[i] = -1;
	}
	
	printf("Enter the total number of page request: ");	
	scanf("%d", &n);	
	int ref_seq[n];
	
	printf("Enter the reference sequence: ");	
	for(i=0;i<n;i++)
	{
		scanf("%d", &ref_seq[i]);
	}
	
	/*Calculation*/
	printf("\nPage frame status after each page request: ");
	printf("\nPage Reference\t\tHit/Miss\tPage Frame Status\n");
	
	for(i=0; i<n; i++)
	{
		printf("\n\t%d",ref_seq[i]); //page request of this step
		
		if(!isPresent(framesTable, numFrames, ref_seq[i])) //if requested page is not present
		{
			printf("\t\tMiss\t ");
			framesTable[pos] = ref_seq[i];	
			pos = (pos+1)% numFrames ;  //maintain FIFO order
			numFaults++ ; 		//increase the num. of faults
			
			printTable(framesTable, numFrames); 
			
		}
		else	//if req. page is present
			printf("\t\tHit\t ");
	}
	//print the total num. of faults
	printf("\n\nTotal number of page faults: %d", numFaults);
	
	return 0;	
}
