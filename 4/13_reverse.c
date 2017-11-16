#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

#define DEBUG_

void reverse_2(char s[], int pos)
{
#ifdef DEBUG
	printf("reverse_2 called for position %d\n", pos);
#endif

	int len = strlen(s);

	if (pos >= len / 2)
		return;

	char tmp = s[pos];
	s[pos] = s[len - pos - 1];
	s[len - pos - 1] = tmp;

	reverse_2(s, pos + 1);
}

////////////////////////////////////////////////

int main()
{
	char s[1000];
	read_line("Enter string", s);

	reverse_2(s, 0);

	printf("Result: %s\n", s);

	return 0;
}

