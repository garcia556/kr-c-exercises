#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 100

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

////////////////////////////////////////////////

int main()
{
	int i = 0;
	char ch;
	puts("Input an integer followed by a char:");

	/* read chars until non digit or EOF */
	while ((ch = getch()) != EOF && isdigit(ch))
		i = 10 * i + ch - 48; /* convert ASCII into int value */

	/* if non digit char was read, push it back into input buffer */
	if (ch != EOF)
		ungetch(ch);
		
	printf("\n\ni = %d, next char in buffer = %c\n", i, getch());
	return 0;
}

