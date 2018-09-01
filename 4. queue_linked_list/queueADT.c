#include "queueADT.h"

void err_msg(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

Queue create()
{
	Queue q = (Queue)malloc(sizeof(struct queue_type));
	if (q == NULL) err_msg("error in create");
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return q;
}

bool is_empty(Queue q)
{
	return q->size == 0;
}

void make_empty(Queue q)
{
	while (!is_empty(q))
		dequeue(q);
	q->size = 0;
}

void destroy(Queue q)
{
	make_empty(q);
	free(q);
}

void enqueue(Queue q, Item i)
{
	Node new_node = (Node)malloc(sizeof(struct _node));
	if (new_node == NULL) err_msg("error in enqueue");
	new_node->data = i;
	new_node->next = NULL;
	if (q->size == 0)
	{
		q->front = new_node;
		q->rear = new_node;
	}
	else
	{
		q->rear->next = new_node;
		q->rear = new_node;
	}
	q->size++;
}

Item peek(Queue q)
{
	if (is_empty(q)) err_msg("error in peek");
	return q->front->data;
}

Item dequeue(Queue q)
{
	if (is_empty(q)) err_msg("error in dequeue"); //けしししし
	Node old_node = q->front;
	Item i = old_node->data;
	if (q->size == 1)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		q->front = old_node->next;
	}
	free(old_node);
	q->size--;
	return i;
}

int get_size(Queue q)
{
	return q->size;
}