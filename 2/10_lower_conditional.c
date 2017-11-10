#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

char lower(char c)
{
	return c + ((c >= 'A' && c <= 'Z') ? 'a' - 'A' : 0);
}

////////////////////////////////////////////////

int main()
{
	// x
	char s[MAX_LINE];
	read_line("Enter string", s);
	int len = strlen(s);

	for (int i = 0; i < len; i++)
		s[i] = lower(s[i]);

	printf("\nResult: %s\n", s);
}

