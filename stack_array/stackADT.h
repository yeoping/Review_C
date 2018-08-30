#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef int Item;
typedef struct stack_type* Stack;

struct stack_type {
	Item *contents;
	int capacity;
	int top;
};

//func
void destroy(Stack s);
void make_empty(Stack s);
bool is_full(Stack s);
bool is_empty(Stack s);
Item peek(Stack s);
Item pop(Stack s);
void reallocate(Stack s);
void push(Stack s, Item i);
Stack create();
void err_msg(char *msg);
///
#endif // !STACKADT_H
