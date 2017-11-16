#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char buf;  /* buffer for ungetch */
int  bufp = 0;      /* next free position in buf */

void ungetch(int c) /* push character back on input */
{
	buf = c;
	bufp = 1;
}

int getch(void) /* get a (possibly pushed back) character */
{
	if (bufp == 0)
		return getchar();

	bufp = 0;
	return buf;
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

