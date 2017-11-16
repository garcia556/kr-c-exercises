#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "_flib.h"

#define NUMBER -127
#define MAXVAL  100 

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[], char r[])
{
	char DELIM = ' ';

	r[0] = '\0';

	char c;
	int word = 0;
	int i = 0;
	int j = 0;
	while ((c = s[i++]) && c != '\0')
	{
		if (!word && c != DELIM)
			word = 1;

		// end of the word
		if (word && c == DELIM)
			break;

		if (word)
			r[j++] = c;
	}
	r[j] = '\0';

	int lens = strlen(s);
	int lenr = strlen(r);
	// shift input string
	for (i = 0; i < lens - lenr - 1; i++)
		s[i] = s[i + j + 1];
	s[i] = '\0';

	// done parsing string
	if (strlen(r) == 0)
		return '\n';

	// non digit
	if (strlen(r) == 1 && !isdigit(r[0]))
		return r[0];

	return NUMBER;
}

////////////////////////////////////////////////

int main()
{
	int type;
	double op2;
	char i[1000];
	char s[1000];

	while (1)
	{
		read_line("Enter operation", i);
		if (strlen(i) == 0)
			return 0;

		while ((type = getop(i, s)))
		{
			if (strlen(s) == 0)
			{
				printf("%.8g\n", pop());
				break;
			}

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
				default:
					printf("error: unknown command %s\n", s);
					break;
			}
		}
	}

	return 0;
}

