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

Item pop(Stack s)
{
	if(is_empty(s)) err_msg("error in push");
	Item i = s->contents[s->top];
	s->top--;	
	return i;
}

Item peek(Stack s)
{
	if (is_empty(s)) err_msg("error in peek");
	return s->contents[s->top];
}

bool is_empty(Stack s)
{
	return s->top == -1;
}

bool is_full(Stack s)
{
	return s->top == s->capacity;
}

void make_empty(Stack s)
{
	s->top = -1;
}

void destroy(Stack s)
{
	free(s->contents);
	free(s);
}