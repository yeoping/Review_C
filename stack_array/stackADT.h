#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>
#include <stdlib.h>

typedef int Item;
typedef struct stack_type* Stack;

struct stack_type {
	Item *contents;
	int capacity;
	int top;
};

//func


///
#endif // !STACKADT_H
