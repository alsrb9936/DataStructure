#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.c"
#include "WhoNightDuty.h"

Employee * What(List * plist, char * name, int day);
void showinfo(Employee * emp);

int main()
{
	List list;
	
	Employee * pemp;
	
	ListInit(&list);
	
	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->num = 1111;
	strcpy(pemp->name,"김씨");
	LInsert(&list,pemp);
	
	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->num = 1112;
	strcpy(pemp->name,"이씨");
	LInsert(&list,pemp);
	
	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->num = 1113;
	strcpy(pemp->name,"최씨");
	LInsert(&list,pemp);
	
	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->num = 1114;
	strcpy(pemp->name,"강씨");
	LInsert(&list,pemp);
	
	pemp = What(&list,"김씨",3);
	showinfo(pemp);
	
	pemp = What(&list,"강씨",15);
	showinfo(pemp);
	
	if(LFirst(&list,&pemp))
	{
		free(pemp);
		for(int i=0;i<3;i++)
		{
			LNext(&list,&pemp);
			free(pemp);
		}
	}
	
	return 0;
	
}

Employee * What(List * plist, char * name, int day)
{
	Employee * pemp;
	int i,num;
	
	num = LCount(plist);
	
	LFirst(plist ,&pemp);
	
	if(strcmp(name,pemp->name)!=0)
	{
		for(i = 0; i<num-1; i++)
		{
			LNext(plist,&pemp);
			if(strcmp(name,pemp->name)==0)
				break;
		}
	}
	
	for(i = 0;i<day;i++)
		LNext(plist,&pemp);
	
	return pemp;
}

void showinfo(Employee * emp)
{
	printf("이름:%s \n",emp->name);
	printf("사번:%d \n",emp->num);
}
