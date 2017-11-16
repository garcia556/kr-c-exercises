#include <stdio.h>
#include <stdlib.h>

int foo()
{
	static int i = 0;
	return i++;
}

////////////////////////////////////////////////

int main()
{
	for (int i = 0; i < 11; i++)
	{
		int x = foo();
		printf("%d\n", x);
	}

	return 0;
}

