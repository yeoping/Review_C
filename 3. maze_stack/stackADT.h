#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct pos Item;
typedef Item Position;
typedef struct _node* Node;
typedef struct stack_type* Stack;

struct pos {
	int x, y;	// pos
};

struct _node {
	Item data;
	struct _node *next;
};

struct stack_type {
	struct _node* top;
};

//func
void err_msg(char *msg);
Stack create();
bool is_empty(Stack s);
void push(Stack s, Item i);
Item peek(Stack s);
Item pop(Stack s);
void make_empty(Stack s);
void destroy(Stack s);
// // //
#endif // !STACKADT_H
