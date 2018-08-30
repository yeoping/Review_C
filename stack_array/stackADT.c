#include "stackADT.h"

void err_msg(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

Stack create()
{
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL) err_msg("error in create\n");
	s->top = -1;	//initialize top
	
}