#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "_flib.h"

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

////////////////////////////////////////////////

void print_top()
{
	printf("Top stack element: %f\n", val[sp-1]);
}

void duplicate()
{
	push(val[sp-1]);
	printf("Top stack element %f duplicated\n", val[sp-1]);
}

void swap_2()
{
	if (sp < 2)
	{
		printf("Stack element count is not enough for swap");
		return;
	}

	double tmp = val[sp-1];
	val[sp-1] = val[sp-2];
	val[sp-2] = tmp;

	printf("Top stack elements swapped\n");
}

void dump()
{
	printf("Dumping stack ...\n");
	for (int i = 0; i < sp; i++)
		printf("[%d]: %f\n", i, val[i]);
	if (sp == 0)
		printf("Stack is empty\n");
}

void clear()
{
	sp = 0;
}

////////////////////////////////////////////////

int main()
{
	char s1[MAX_LINE];
	char s2[MAX_LINE];
	char s3[MAX_LINE];

	read_line("Enter double num 1", s1);
	read_line("Enter double num 2", s2);
	read_line("Enter double num 3", s3);

	push(atof(s1));
	push(atof(s2));

	dump();
	print_top();

	duplicate();
	dump();

	push(atof(s3));
	swap_2();
	dump();

	clear();
	dump();
}

