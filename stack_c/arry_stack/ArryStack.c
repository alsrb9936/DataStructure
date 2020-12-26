#include <stdio.h>
#include <stdlib.h>
#include "ArryStack.h"

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}

int SIsempty(Stack * pstack)
{
	if(pstack->topIndex == -1)
		return TRUE;
	return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	pstack->topIndex +=1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack)
{
	int data;
	
	if(SIsempty(pstack)==1)
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
		
	data = pstack->stackArr[pstack->topIndex];
	pstack->topIndex -=1;
	
	return data;
}

Data SPeek(Stack *pstack)
{
	if(SIsempty(pstack)==1)
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	return pstack->stackArr[pstack->topIndex];
}
