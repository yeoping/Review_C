#ifndef STACKADT_H
#define STACKADT_H

typedef int Item;
typedef struct _node* Node;
typedef struct stack_type* Stack;

struct _node {
	Item data;
	struct _node *next;
};

struct stack_type {
	struct _node* top;
};

//func

// // //
#endif // !STACKADT_H
