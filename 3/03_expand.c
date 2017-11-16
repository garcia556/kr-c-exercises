#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "_flib.h"

void expand(char s1[], char s2[])
{
	char c;
	int i1 = 0;
	int i2 = 0;
	while ((c = s1[i1++]) && c != '\0')
	{
		c = tolower(c);

		// leave the character as is if it's not -
		if (c != '-')
		{
			s2[i2++] = c;
			continue;
		}

		// skip leading or trailing -
		if (i1 == 1 || s1[i1] == '\0')
		{
			s2[i2++] = c;
			continue;
		}

		char from = s1[i1 - 2];
		char to = s1[i1];

		// skip if there range start > range end
		if (to - from <= 0)
		{
			s2[i2++] = c;
			continue;
		}

		for (char ic = from + 1; ic < to; ic++)
			s2[i2++] = ic;
	}

	s2[i2] = '\0';
}

////////////////////////////////////////////////

int main()
{
	char s1[MAX_LINE];
	char s2[MAX_LINE];

	read_line("Enter string", s1);

	expand(s1, s2);

	printf("Result:\n%s\n", s2);
}

