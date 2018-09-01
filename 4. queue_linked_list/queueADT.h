#ifndef QUEUEADT_H
#define QUEUEADT_H

typedef int Item;
typedef struct _node* Node;
typedef struct queue_type* Queue;

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

// // // //
#endif // !QUEUEADT_H
