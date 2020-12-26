#include <stdio.h>
#include "ListStack.h"
#include "ListStack.c"

int main()
{
	Stack stack;
	StackInit(&stack);
	
	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	
	printf("TOP DATA! %d\n",SPeek(&stack));
	
	while(!SIsEmpty(&stack))
	{
		printf("POP DATA! %d\n",SPop(&stack));
	}
	
	return 0;
}