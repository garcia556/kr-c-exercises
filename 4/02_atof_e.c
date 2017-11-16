#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "_flib.h"

double atof_2(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)  /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	int len = strlen(s);
	if (len >= 3)
	{
		if (tolower(s[len - 3]) == 'e')
			power *= pow(10, atoi(s + (len - 1)));
	}

	return sign * val / power;
}

////////////////////////////////////////////////

int main()
{
	char s[MAX_LINE];

	read_line("Enter float number", s);

	double d = atof_2(s);

	printf("Result:\n%f\n", d);
}

