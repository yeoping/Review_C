#ifndef QUEUEADT_H
#define QUEUEADT_H
#include <stdbool.h>
#include <stdio.h>

typedef int Item;
typedef struct queue_type* Queue;

struct queue_type {
	int *contents;
	int front;
	int rear;
	int capacity;
	int size;	//the number of datas
};

//func
void reallocate(Queue q);
Item dequeue(Queue q);
Item peek(Queue q);
void enqueue(Queue q, Item i);
bool is_full(Queue q);
bool is_empty(Queue q);
void destroy(Queue q);
void make_empty(Queue q);
Queue create();
void err_msg(char *msg);
// // //
#endif // !QUEUEADT_H
