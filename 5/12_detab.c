#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

#define STR_SIZE 1000
#define TABSTOP '\t'

/* print longest input line; specialized version */
int main(int argc, char *argv[])
{
	argv++;

	int m, n;
	while (--argc > 0)
	{
		if (*argv[0] == '-')
			m = - atoi(*argv);
		else
		if (*argv[0] == '+')
			n = atoi(*argv);

		argv++;
	}
	printf("Got m: %d, n: %d\n", m, n);

	char s[STR_SIZE];
	while (1)
	{
		read_line("Enter string", s);
		if (s[0] == '\0')
		{
			printf("\n");
			break;
		}

		int len = strlen(s);
		int col = 0;
		for (int i = 0; i < len; i++)
		{
			if (i < m)
			{
				putchar(s[i]);
				continue;
			}

			col++;
			putchar(s[i]);

			if (col == n)
			{
				putchar(TABSTOP);
				col = 0;
			}
		}
		putchar('\n');
	}

	return 0;
}

