#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

#define SIZE 1000

void strncpy_2(char *s, char *t, int n)
{
	int i = 0;
	while ((*s++ = *t++) != '\0' && i < n - 1)
		i++;
}

////////////////////////////////////

int main()
{
	char s[SIZE];
	char t[SIZE];
	int n;

	read_line("Enter char count to copy", s);
	n = atoi(s);
	read_line("Enter string to copy", s);

	strncpy_2(t, s, n);

	printf("Result: %s\n", t);

	return 0;
}

