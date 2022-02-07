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


