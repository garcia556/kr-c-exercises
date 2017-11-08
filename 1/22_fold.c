#include <stdio.h>

#define	MAXLINE	1000	/* maximum input line size */
#define MAXSIZE 16

char line[MAXLINE];     /* current input line */

int getlinex();

/* print longest input line; specialized version */
int main()
{
	int len;
	extern char line[];

	while ((len = getlinex()) > 0)
	{
		int blank_index = -1;
		for (int i = 0; i < len; ++i)
		{
			// count spaces
			if (line[i] == ' ' || line[i] == '\t')
				blank_index = i;

			// got to the end of the line
			if (i > 0 && i % (MAXSIZE - 1) == 0)
			{
				// no blanks found
				if (blank_index == -1)
					putchar('-');
				else
				{
					int spaces = MAXSIZE - blank_index;
					for (int k = 0; k < spaces; k++)
						putchar('\b');
					for (int k = 0; k < spaces; k++)
						putchar(' ');
				}

				putchar('|');
				putchar('\n');
				blank_index = -1;
			}

			putchar(line[i]);
		}
	}

	return 0;
}

/* getlinex:  specialized version */
int getlinex()
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE-1
		&& (c=getchar()) != EOF && c != '\n'; ++i)
			line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
