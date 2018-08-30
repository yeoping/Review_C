#include "stackADT.h"

int main()
{
	Stack s1 = create();
	for (int i = 0; i < 1500; i++)
	{
		push(s1, i);	//0~1500 input
	}

	while (s1->top != NULL)
	{
	printf("%d\n", pop(s1));	//s->top부터 하나씩 data 출력
	}

	return 0;
}