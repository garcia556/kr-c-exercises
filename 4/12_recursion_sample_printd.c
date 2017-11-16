#include <stdio.h>
#include <stdlib.h>
#include "_flib.h"

void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }

    if (n / 10)
        printd(n / 10);

    putchar(n % 10 + '0');
}

////////////////////////////////////////////////

int main()
{
	char s[1000];
	read_line("Enter integer number", s);
	int n = atoi(s);
	printd(n);
	putchar('\n');

	return 0;
}

