#include <stdio.h>
#include <ctype.h>

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

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

	for (*pn = 0; c != '\n'; c = getchar())
	{
		if (!isdigit(c))
		{
			if (c != EOF)
				*pn = 0;
			break;
		}

		*pn = 10 * *pn + (c - '0');
	}

	*pn *= sign;

	return 1;
}

////////////////////////////////////

#define SIZE 1000

// to end the input press enter for a new element and use Ctrl+D (EOF)
int main()
{
	int n;
	int array[SIZE];
	for (n = 0; n < SIZE; n++)
	{
		int res = getint(&array[n]);
		if (res == EOF)
			break;
	}

	for (int i = 0; i < n; i++)
		printf("[%d] => %d\n", i, array[i]);
}

