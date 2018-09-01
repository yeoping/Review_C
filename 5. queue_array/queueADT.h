#ifndef QUEUEADT_H
#define QUEUEADT_H
#include <stdbool.h>

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

// // //
#endif // !QUEUEADT_H
