#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

int getop(char s[])
{
	static int last = -1;

	int i, c;

	if (last != -1)
	{
		c = last;
		last = -1;
	}
	else
	{
		c = getchar();
		s[0] = c;
	}

	while (c == ' ' || c == '\t')
	{
		c = getchar();
		s[0] = c;
	}

	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c;

	i = 0;

	if (isdigit(c))   /* collect integer part */
		while (isdigit(s[++i] = c = getchar()))
			;

	if (c == '.')     /* collect fraction part */
		while (isdigit(s[++i] = c = getchar()))
			;

	s[i] = '\0';

	if (c != EOF)
		last = c;

	return NUMBER;
}

////////////////////////////////////////////////

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	int op3, op4;

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
				printf("%.8g\n", pop());
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
			case '\n':
				printf("%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}

