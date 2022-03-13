/*   Optimal page replacement   */

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
	int i,j,k,numFrames, n, numFaults=0 , current , futurePos[20], max, optIndex;
	
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
	
	/*calculation*/
	for(i=0; i<n; i++)
	{
		printf("\n  %d",ref_seq[i]);
		if(!isPresent(framesTable, numFrames, ref_seq[i])) //if the requested page is present
		{
			printf("\t\t\tMiss\t ");
			for(j=0; j<numFrames; j++)
			{
				current = framesTable[j];	//one of current pages in table
				for(k = i+1; k<n ; k++)		//check the future pages in sequence
				{
					if(current == ref_seq[k]) //when current page is found among future pages in seq.
					{
						futurePos[j] = k; //store the index
						break;
					}
					else		//if current page is not found in future seq
						futurePos[j] = 99999;	//this initialization is important
				}
			}
			max = -999;
			for(j=0; j<numFrames; j++)
			{
				if(futurePos[j] > max)  //check the furthest from the indexes
				{
					max = futurePos[j];
					optIndex = j;   	//store the index of furthest
				}
			}
			framesTable[optIndex] = ref_seq[i];	//replace the page which is furthest in future of seq.
			numFaults++;
			
			printTable(framesTable, numFrames);
			
		}
		else
			printf("\t\t\tHit\t ");
	}
	printf("\n\nTotal number of page faults: %d", numFaults);
	
	return 0;
	
}
