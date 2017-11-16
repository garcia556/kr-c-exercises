#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "_flib.h"

#define BUFSIZE 1000

char buf[BUFSIZE];  /* buffer for ungetch */
int  bufp = 0;      /* next free position in buf */

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungets(char s[])
{
    if (bufp + strlen(s) > BUFSIZE)
	{
        printf("ungets: too many characters\n");
		return;
	}

	char c;
	int i = 0;
	while ((c = s[i++]) && c != '\0')
		ungetch(c);
}

////////////////////////////////////////////////

int main()
{
	char s[1000];
	read_line("Enter string: ", s);

	ungets(s);

	printf("top 3 chars in buffer: %c, %c, %c\n", getch(), getch(), getch());
}

