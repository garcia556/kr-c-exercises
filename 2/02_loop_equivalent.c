#include <stdio.h>

#define MAX_LINE 1000

int main()
{
	char s[MAX_LINE];
	for (int i = 0; i < MAX_LINE - 1; ++i)
	{
		char c = getchar();
		if (c == '\n' || c == EOF)
			break;

		s[i] = c;
	}

	printf("%s\n", s);
}

