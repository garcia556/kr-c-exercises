#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int __getline(char line[], int maxline);

/* print longest input line */
int main()
{
    int len;            /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = __getline(line, MAXLINE)) > 0)
	{
		int i;
		for (i = len - 2; i >= 0; --i)
			putchar(line[i]);
		printf("\n");
	}

    return 0;
}

/* getline:  read a line into s, return length */
int __getline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
