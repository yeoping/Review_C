#include "stackADT.h"
#define INIT_CAPACITY 100

void err_msg(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

Stack create()
{
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL) err_msg("error in create");
	s->contents = (Item*)malloc(sizeof(Item));
	if (s->contents == NULL)
	{
		err_msg("error in create");
		free(s);
	}
	s->capacity = INIT_CAPACITY;
	s->top = -1;	//initialize top
	return s;
}