#include <stdio.h>
#include <ctype.h>

/* getint:  get next integer from input into *pf */
int getfloat(double *pf)
{
	char c;
	int sign;
	double power;

	while (isspace(c = getchar()))   /* skip white space */
		;

	// first char after space except +/-/EOF
	if (!isdigit(c) && c != '+' && c != '-')
		return EOF;

	// save negative sign if first char is -
	sign = (c == '-') ? -1 : 1;

	// advance character by one skipping +/-
	if (c == '+' || c == '-')
		c = getchar();

	for (*pf = 0.0; c != '\n'; c = getchar())
	{
		if (!isdigit(c))
		{
			if (c != EOF && c != '.')
				*pf = 0.0;
			break;
		}

		*pf = 10.0 * *pf + (c - '0');
	}

	// get next char after .
	if (c == '.')
		c = getchar();

	for (power = 1.0; c != '\n'; c = getchar())
	{
		if (!isdigit(c))
		{
			if (c != EOF)
				*pf = 0.0;
			break;
		}

		*pf = 10.0 * *pf + (c - '0');
		power *= 10;
	}

	*pf *= sign;
	*pf /= power;

	return 1;
}

////////////////////////////////////

#define SIZE 1000

// to end the input press enter for a new element and use Ctrl+D (EOF)
int main()
{
	int n;
	double array[SIZE];
	for (n = 0; n < SIZE; n++)
	{
		double res = getfloat(&array[n]);
		if (res == EOF)
			break;
	}

	for (int i = 0; i < n; i++)
		printf("[%d] => %f\n", i, array[i]);
}

