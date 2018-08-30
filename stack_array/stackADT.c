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

void push(Stack s, Item i)
{
	if (s->top == s->capacity) reallocate(s);
	s->top++;
	s->contents[s->top] = i;
}

void reallocate(Stack s)
{
	Item *tmp = (Item*)malloc(sizeof(2 * sizeof(s->capacity) + sizeof(Item)));
	if (tmp == NULL)err_msg("error in reallocate");
	for (int i = 0; i < s->capacity; i++)	//duplicate array
		tmp[i] = s->contents[i];
	free(s->contents);
	s->contents = tmp;
	s->capacity *= 2;
}