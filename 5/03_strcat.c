#include <stdio.h>
#include <string.h>
#include "_flib.h"

#define SIZE 1000

void strcat_2(char *s, char *t)
{
	while (*s != '\0') // advance s pointer to the end
		s++;
	while ((*s++ = *t++) != '\0') // copy t chars to s
		;
}

////////////////////////////////////

int main()
{
	char s[SIZE];
	char t[SIZE];

	read_line("Enter string 1", s);
	read_line("Enter string 2", t);

	strcat_2(s, t);

	printf("Result: %s\n", s);

	return 0;
}

