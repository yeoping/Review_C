#define _CRT_SECURE_NO_WARNINGS
#include "queueADT.h"

int main()
{
	//test code
	Queue q = create();
	printf("# enqueue\n");
	for (int i = 0; i < 3; i++)
	{
		printf("  %d\n", i);
		enqueue(q, i);
	}

	printf("# dequeue \n");
	while (q->size > 0)
		printf("  %d\n", dequeue(q));
	return 0;
}