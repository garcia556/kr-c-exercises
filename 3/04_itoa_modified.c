#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "_flib.h"

/* reverse:  reverse string s in place */
void reverse_2(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itoa:  convert n to characters in s */
void itoa_2(int n, char s[])
{
	int i, sign;
	long int ln = n; // use doubleword for internal calculations

	if ((sign = ln) < 0)
		ln = - ln; // reset sign

	i = 0;
	do
	{
		s[i++] = ln % 10 + '0';
    }
	while ((ln /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';

	reverse_2(s);
}

////////////////////////////////////////////////

int main()
{
	char s[MAX_LINE];

	read_line("Enter number", s);
	int n = atoi(s);

	itoa_2(n, s);

	printf("Result:\n%s\n", s);
}

