#include "stackADT.h"
#define INIT_CAPACITY 20

void err_msg(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

Stack create()
{
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL) err_msg("error in create");
	s->contents = (Item*)malloc(INIT_CAPACITY*sizeof(s->contents));
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
	if (is_full(s)) reallocate(s);
	s->top++;
	s->contents[s->top] = i;
}

void reallocate(Stack s)
{
	/*
	Item *tmp = (Item*)malloc(sizeof(2 * s->capacity * sizeof(Item)));
	printf("Test\n");
	if (tmp == NULL)err_msg("error in reallocate");
	for (int i = 0; i <= s->top; i++)	//duplicate array
		tmp[i] = s->contents[i];
	free(s->contents);
	s->contents = tmp;
	s->capacity *= 2;*/
	s->contents = realloc(s->contents, 2 * s->capacity * sizeof(Item));
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
	return s->top +1 == s->capacity;	//s->top : 0 1 2 3 4 ,  s->top + 1과 비교해야함
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