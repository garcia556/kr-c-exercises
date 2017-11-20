#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define LAST_DEFAULT 10

int getline_2(char *, int);
char *alloc(int);

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline_2(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else
		{
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}

	return nlines;
}

/* writelines:  write output lines */
void writelines(char *lineptr[], int total, int last)
{
	// line count to show
	int n = total - last;

	// show all if last > total
	if (n < 0)
		n = 0;

	for ( ; n < total; n++)
		printf("%s\n", lineptr[n]);
}

////////////////////////////////

#define MAXLINES 5000

char *lineptr[MAXLINES];

int main(int argc, char *argv[])
{
	int last = 0;
	if (argc == 2 && argv[1][0] == '-')
		last = - atoi(argv[1]);

	if (last == 0)
		last = LAST_DEFAULT;

	int nlines; /* number of input lines read */

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		printf("\n\nLast %d lines:\n", last);
		writelines(lineptr, nlines, last);
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
}

////////////////////////////////

/* getline:  get line into s, return length */
int getline_2(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];  /* storage for alloc */
static char *allocp = allocbuf;   /* next free position */

char *alloc(int n)  /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else      /* not enough room */
        return 0;
}

