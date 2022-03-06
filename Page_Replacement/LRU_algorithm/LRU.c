

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
	int i,j,k,numFrames, n, numFaults=0 , pos=0, current, lastPos[10], flag=0, min, lruIndex;
	
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
		
	printf("\nPage frame status after each page request: ");
	printf("\nPage Reference\t\tHit/Miss\tPage Frame Status\n");
	
	
