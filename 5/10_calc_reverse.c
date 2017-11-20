#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVAL 100
static double STACK[MAXVAL];
static double *sp = STACK;

void push(double f)
{
	if (sp - STACK >= MAXVAL)
	{
        printf("error: stack full, can't push %g\n", f);
		return;
	}

	// save value and increment the pointer
	*sp++ = f;
}

double pop()
{
	if (sp == STACK)
	{
        printf("error: stack empty\n");
        return 0.0;
	}

	// first decrement pointer, then get the value
	return *(--sp);
}

////////////////////////////////////////////////

int is_operator(char c)
{
	if (
			c == '+'
		||	c == '-'
		||	c == '*'
		||  c == '/'
		)
		return 1;

	return 0;
}

void process_operator(char type)
{
	double op2;

	switch (type)
	{
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
			printf("error: unknown command %c\n", type);
			break;
	}
}

int main(int argc, char *argv[])
{
	int i = 0;
	char **p = argv + 1;

	// first pushing numbers
	while (p - argv < argc)
	{
		// exit when got operator
		if (strlen(*p) == 1 && is_operator(*p[0]))
			break;

		float f = atof(*p);
		push(f);
		p++;
	}

	// set pointer to the end
	argv += argc - 1;

	// processing operators backwards
	while (argv >= p)
	{
		char type = *argv[0];
		process_operator(type);
		argv--;
	}

	printf("%.8g\n", pop());

	return 0;
}

