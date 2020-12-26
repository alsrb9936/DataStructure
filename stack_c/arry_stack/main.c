#include <stdio.h>
#include "ArryStack.h"
#include "ArryStack.c"

int main()
{
	Stack stack1;
	int data;
	
	StackInit(&stack1);
	
	SPush(&stack1,1); SPush(&stack1,2); 
	SPush(&stack1,3); SPush(&stack1,4);
	
	printf("TopData: %d \n",SPeek(&stack1));
	
	while(!SIsempty(&stack1))
		printf("%d ", SPop(&stack1)); 

	
	return 0;
}
