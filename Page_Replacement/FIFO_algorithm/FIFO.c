

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

