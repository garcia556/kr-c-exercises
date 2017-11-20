#include <stdio.h>
#include <string.h>

#define ALLOCSIZE 10000 /* size of available space */
#define MAXLEN 1000   /* max length of any input line */
int getline_2(char *, int);
void qsort(char *[], int, int);

/* readlines:  read input lines */
int readlines(char *lineptr[], char *storage, int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = storage;

	nlines = 0;
	while ((len = getline_2(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (storage - p + len) > MAXLEN)
			return -1;
		else
		{
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}

	return nlines;
}

/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

////////////////////////////////

#define MAXLINES 5000

int main()
{
	char *lineptr[MAXLINES];
	char storage[ALLOCSIZE];

	int nlines; /* number of input lines read */
	if ((nlines = readlines(lineptr, storage, MAXLINES)) >= 0)
	{
		qsort(lineptr, 0, nlines-1);
		printf("\n\nLines:\n");
		writelines(lineptr, nlines);
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

/* swap:  interchange v[i] and v[j] */
void swap_2(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* qsort:  sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;

	if (left >= right)   /* do nothing if array contains */
		return;          /* fewer than two elements */
	swap_2(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap_2(v, ++last, i);
	swap_2(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

