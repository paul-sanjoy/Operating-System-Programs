/*   Find most efficient algorithm   */

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


int main()
{
	int i,j,nb,np,temp,totalFrag1=0, totalFrag2=0, totalFrag3=0, num1 =0, num2 =0, num3=0;
	
	/*Inputs and initialization*/
	printf("Enter the number of Memory blocks: ");
	scanf("%d",&nb);
	
	mBlock blck1[nb];
	mBlock blck2[nb];
	mBlock blck3[nb];
	
	printf("Enter the size of the memory blocks: ");
	for(i=0;i<nb;i++)
	{
		scanf("%d",&temp);
		blck1[i].unused = temp ;
		blck1[i].used = 0 ;		
		blck2[i].unused = temp ;
		blck2[i].used = 0 ;	 
		blck3[i].unused = temp ;
		blck3[i].used = 0 ;	
	}
	
	
	printf("\nEnter the number of Processes: ");
	scanf("%d",&np);
	
	Process proc1[np];
	Process proc2[np];
	Process proc3[np];
	
	printf("Enter the size of the Processes: ");
	for(i=0;i<np;i++)
	{
		scanf("%d",&temp);
		proc1[i].size = temp;
		proc1[i].allocated = 0;
		proc2[i].size = temp;
		proc2[i].allocated = 0;
		proc3[i].size = temp;
		proc3[i].allocated = 0;
	}
	
		/*process and Outputs*/
	totalFrag1 = firstFit(blck1,proc1,nb,np,&num1);
	totalFrag2 = worstFit(blck2,proc2,nb,np,&num2);	
	totalFrag3 = bestFit(blck3,proc3,nb,np,&num3);
	
	showChart(totalFrag1,totalFrag2,totalFrag3,num1,num2,num3);
	
	printf("\n-----------------------------------------------------------");
	printf("\n\nThe best algorithm for this data set is: ");
	if(num1 < num2 && num1 < num3)
		printf("first fit");
	else if (num2 < num1 && num2 < num3)
		printf("worst fit");
	else if (num3 < num1 && num3< num2)
		printf("best fit");
	else if (num1 == num2 && num1 < num3 && num2 < num3)
	{
		if (totalFrag1 < totalFrag2)
			printf("first fit");
		else
			printf("worst fit");
	}
	else if (num2 == num3 && num2< num1 && num3 < num1 )
	{
		if (totalFrag2 < totalFrag3)
			printf("worst fit");
		else
			printf("best fit");
	}
	else if (num3 == num1 && num3 < num2 && num1 < num2)
	{
		if (totalFrag3 < totalFrag1)
			printf("best fit");
		else
			printf("first fit");
	}
	else //if num1==num2==num3
	{
		if(totalFrag1 <= totalFrag2 && totalFrag1 <= totalFrag3) //if fragments are same, first fit is declared efficient
			printf("first fit");
		else if(totalFrag2 < totalFrag1 && totalFrag2 < totalFrag3)
			printf("worst fit");
		else
			printf("best fit");
	}
	
	return 0 ;
}

