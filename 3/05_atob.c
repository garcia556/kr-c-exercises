#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "_flib.h"

#define BASE 10

void itob(int n, char s[], int b)
{
	long int ln = n;
	int t;
	char c;

	int i = 0;
	do
	{
		t = ln % b;
		if (t < BASE)
			c = '0';
		else
		{
			c = 'a';
			t -= BASE;
		}

		s[i++] = t + c;
	}
	while ((ln /= b) != 0);
	s[i] = '\0';

	reverse(s, 0, i - 1);
}

////////////////////////////////////////////////

int main()
{
	char s[MAX_LINE];

	read_line("Enter number in decimal", s);
	int n = atoi(s);

	read_line("Enter base", s);
	int b = atoi(s);

	itob(n, s, b);

	printf("Result:\n%s\n", s);
}

