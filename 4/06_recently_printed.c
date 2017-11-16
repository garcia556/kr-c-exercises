#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP   100   /* max size of operand or operator */
#define NUMBER  '0'   /* signal that a number was found */

#define MAXVAL  100   /* maximum depth of val stack */

int sp = 0;           /* next free stack position */
double val[MAXVAL];   /* value stack */

/* push:  push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

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

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

	// sin, exp, pow
	if (s[0] == 's' || s[0] == 'e' || s[0] == 'p' || s[0] == 'z')
		return s[0];

    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;     /* not a number */

    i = 0;

    if (isdigit(c) || c == '-')   /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')     /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

////////////////////////////////////////////////

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	int op3, op4;
	double last;

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op3 = pop();
				op4 = pop();
				int res = op4 % op3;
				push(res);
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case 'p':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case '\n':
				if (sp > 0)
					last = val[sp-1];

				printf("%.8g\n", pop());
				break;
			case 'z':
				printf("%.8g\n", last);
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}

