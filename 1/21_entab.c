#include <stdio.h>

#define	MAXLINE	1000	/* maximum input line size */
#define TABSIZE 8

char line[MAXLINE];     /* current input line */

int getlinex(void);
/* print longest input line; specialized version */
main()
{
	int len;
	extern char line[];

	while ((len = getlinex()) > 0)
	{
		int i;
		int spaces = 0;
		int prev;
		for (i = 0; i < len; ++i)
		{
			// count spaces
			if (line[i] == ' ')
				spaces++;
			else
			{
				// if spaces just finished - replace them
				if (prev == ' ')
				{
//putchar('X');
//printf("%d", spaces);
					int k;
					for (k = 0; k < spaces / TABSIZE; ++k)
						putchar('\t');
					for (k = 0; k < spaces % TABSIZE; ++k)
						putchar(' ');
				}

				putchar(line[i]);

				// reset space counter
				spaces = 0;
			}

			prev = line[i];
		}
	}

	return 0;
}
/* getlinex:  specialized version */
int getlinex(void)
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
