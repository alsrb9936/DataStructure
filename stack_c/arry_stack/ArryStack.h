#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _arryStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
}ArryStack;

typedef ArryStack Stack;

void StackInit(Stack * pstack);
int SIsempty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif