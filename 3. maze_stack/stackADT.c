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
	s->top = NULL;
	return s;
}

bool is_empty(Stack s)
{
	return s->top == NULL;
}

void push(Stack s, Item i)
{
	Node new_node = (Node)malloc(sizeof(struct _node));
	if (new_node == NULL)err_msg("error in push");
	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
}

Item peek(Stack s)
{
	if (is_empty(s))err_msg("error in peek");
	return s->top->data;
}

Item pop(Stack s)
{
	if (is_empty(s)) err_msg("error in pop");
	Node tmp = s->top;
	Item i = tmp->data;
	s->top = tmp->next;
	free(tmp);
	return i;
}

void make_empty(Stack s)
{
	while (!is_empty(s))
		pop(s);
}

void destroy(Stack s)
{
	make_empty(s);
	free(s);
}