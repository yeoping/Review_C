#ifndef QUEUEADT_H
#define QUEUEADT_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pos Position;
typedef Position Item;
typedef struct _node* Node;
typedef struct queue_type* Queue;

struct pos {
	int x, y;
};

struct _node {
	Item data;
	struct _node *next;
};


struct queue_type {
	struct _node *front;	//data dequeue
	struct _node *rear;		//data enqueue
	int size;	//the number of queue lists
};

//func
int get_size(Queue q);
Item dequeue(Queue q);
Item peek(Queue q);
void enqueue(Queue q, Item i);
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
Queue create();
void err_msg(char *msg);
// // // //
#endif // !QUEUEADT_H
