#include <stdio.h>

#define	MAXLINE	1000	/* maximum input line size */
#define TABSIZE 8

char line[MAXLINE];     /* current input line */

int getline(void);
/* print longest input line; specialized version */
main()
{
	int len;
	extern char line[];

	while ((len = getline()) > 0)
	{
		int i;
		int last = 0;
		for (i = 0; i < len; ++i)
		{
			if (line[i] == '\t')
			{
				int k;
				for (k = 0; k < TABSIZE - last % TABSIZE; ++k)
					putchar(' ');
				last = 0;
				continue;
			}

			putchar(line[i]);
			last++;
		}
	}

	return 0;
}
/* getline:  specialized version */
int getline(void)
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
