#include <stdio.h>
#include <string.h>
#include "_flib.h"

#define SIZE 1000

int strend(char *s, char *t)
{
	char *last = NULL;

	// looking for a first equal character
	for ( ; *s != '\0'; s++)
		// recording last char found
		if (*s == *t)
			last = s;

	// no char found
	if (last == NULL)
		return 0;

	// restoring pointer to the char found
	s = last;

	// checking all further characters
	for ( ; *s == *t; s++, t++)
		// all the characters are equal
		if (*s == '\0' && *t == '\0')
			return 1;

	return 0;
}

////////////////////////////////////

int main()
{
	char s[SIZE];
	char t[SIZE];

	read_line("Enter string 1", s);
	read_line("Enter string 2", t);

	int res = strend(s, t);

	printf("Result: %d\n", res);

	return 0;
}

