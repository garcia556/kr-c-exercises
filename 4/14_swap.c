#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

// not sure how to make this work without pointers
#define swap(t, x, y) { t tmp = *x; *x = *y; *y = tmp; }

////////////////////////////////////////////////

int main()
{
	char s[1000];
	int n1, n2;
	long int ln1, ln2;

	read_line("Enter integer X", s);
	n1 = atoi(s);

	read_line("Enter integer Y", s);
	n2 = atoi(s);

	read_line("Enter long integer X", s);
	ln1 = atoi(s);

	read_line("Enter long integer Y", s);
	ln2 = atoi(s);

	int* pn1 = &n1;
	int* pn2 = &n2;
	long int* pln1 = &ln1;
	long int* pln2 = &ln2;

	swap(int, pn1, pn2);
	swap(long int, pln1, pln2);

	printf("Integer X1 / Y: %d / %d\n", n1, n2);
	printf("Long integer X / Y: %ld / %ld\n", ln1, ln2);

	return 0;
}

