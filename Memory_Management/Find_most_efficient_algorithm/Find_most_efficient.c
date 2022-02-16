

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


