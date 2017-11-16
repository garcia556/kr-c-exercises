#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

#define DEBUG_

void itoa_2(int n, int i, char s[])
{
#ifdef DEBUG
	printf("itoa_2 called for integer %d\n", n);
#endif

	int sign;

	// remove sign
	if ((sign = n) < 0)
		n = -n;

	int current	= n % 10;
	int next	= n / 10;

	s[i++] = current + '0';

	// termination condition
	if (next == 0)
	{
		if (sign < 0)
			s[i++] = '-';
		s[i] = '\0';
		reverse(s, 0, strlen(s));
		return;
	}

	itoa_2(next, i, s);
}

////////////////////////////////////////////////

int main()
{
	char s[1000];
	read_line("Enter integer number", s);
	int n = atoi(s);

	itoa_2(n, 0, s);
	printf("String from integer: %d\n", n);

	return 0;
}

