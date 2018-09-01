#include "queueADT.h"
#define INIT_CAPACITY 10
#include <stdlib.h>

void err_msg(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

Queue create()
{
	Queue q = (Queue)malloc(sizeof(struct queue_type));
	if (q == NULL) err_msg("error in create");
	q->contents = (Item *)malloc(INIT_CAPACITY * sizeof(Item));
	if (q->contents == NULL)
	{
		free(q);
		err_msg("error in create");
	}
	q->front = 0;
	q->rear = -1;
	q->capacity = INIT_CAPACITY;
	q->size = 0;
	return q;
}

void make_empty(Queue q)
{
	//free(q->contents); 다시 사용할꺼라 굳이 free해줄 필요..?
	q->front = 0;
	q->rear = -1;
	q->size = 0;
}

void destroy(Queue q)
{
	free(q->contents);
	free(q);
}

bool is_empty(Queue q)
{
	return q->size == 0;
}

bool is_full(Queue q)
{
	return q->size == q->capacity;
}

void enqueue(Queue q, Item i)
{
	if (is_full(q)) reallocate(q);
	q->rear = (q->rear + 1) % q->capacity;
	q->contents[q->rear] = i;
	q->size++;
}

Item peek(Queue q)
{
	if (is_empty(q))err_msg("error in peek");
	return q->contents[q->front];
}

Item dequeue(Queue q)
{
	if (is_empty(q))err_msg("error in dequeue");
	Item i = q->contents[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	return i;
}

void reallocate(Queue q)
{
	printf("reallocation...\n");
	
	Item *tmp = (Item*)malloc(2 * q->capacity * sizeof(Item));
	if (tmp == NULL)err_msg("error in reallocate");
	int j = q->front;
	for (int i = 0; i < q->size; i++)
	{
		tmp[i] = q->contents[j];
		j = (j + 1) % q->capacity;
	}
	free(q->contents);
	q->front = 0;
	q->rear = q->size - 1;
	q->capacity *= 2;
	q->contents = tmp;

	/*	내장함수 realloc 사용하면 편함
	q->contents=realloc(q->contents, 2 * q->capacity * sizeof(Item));
	q->capacity *= 2;
	*/
}