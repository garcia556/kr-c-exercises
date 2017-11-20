#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_flib.h"

#define SIZE 1000

void strncat_2(char *s, char *t, int n)
{
	while (*s != '\0') // advance s pointer to the end
		s++;
	int i = 0;
	while ((*s++ = *t++) != '\0' && i < n - 1) // copy t chars to s
		i++;
}

////////////////////////////////////

int main()
{
	char s[SIZE];
	char t[SIZE];
	int n;

	read_line("Enter char count to cat", s);
	n = atoi(s);
	read_line("Enter string 1", s);
	read_line("Enter string 2", t);

	strncat_2(s, t, n);

	printf("Result: %s\n", s);

	return 0;
}

