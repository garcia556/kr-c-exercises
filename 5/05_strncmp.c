#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_flib.h"

#define SIZE 1000

int strncmp_2(char *s,  char *t, int n)
{
	for (int i = 0; *s == *t && i < n - 1; s++, t++, i++)
		if (*s == '\0')
			return 0;

	return *s - *t;
}

////////////////////////////////////

int main()
{
	char s[SIZE];
	char t[SIZE];
	int n;

	read_line("Enter char count to cmp", s);
	n = atoi(s);
	read_line("Enter string 1", s);
	read_line("Enter string 2", t);

	int res = strncmp_2(s, t, n);

	printf("Result: %d\n", res);

	return 0;
}

