#include "stackADT.h"

int main()
{
	Stack s1 = create();
	for (int i = 0; i < 1500; i++)
	{
		push(s1, i);
	}

	for (int i = 0; i < 1500; i++)
	{
		printf("%d\n", s1->contents[i]);
	}
	return 0;
}