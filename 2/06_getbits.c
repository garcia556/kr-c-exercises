#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

#define MAX_LINE 1000

/* getbits:  get n bits from position p */
unsigned int getbits(unsigned int x, int p, int n)
{
	return (x >> (p +1 -n)) & gen_bitmask_full(n);
}

////////////////////////////////////////////////

int main()
{
	// x
	char xStr[MAX_LINE];
	read_line("Enter x", xStr);
	int x = atoi(xStr);
	char xStrBin[MAX_LINE];
	itoa(x, xStrBin, 2);
	int xLen = strlen(xStrBin);
	printf("X binary: %s\n", xStrBin);

	// p, n
	char pStr[MAX_LINE];
	char nStr[MAX_LINE];
	read_line("Enter p", pStr);
	read_line("Enter n", nStr);
	int p = atoi(pStr);
	int n = atoi(nStr);

	if (n > p)
		n = p + 1;

	// calc
	int bits = getbits(x, p, n);
	char bitsStrBin[MAX_LINE];
	itoa(bits, bitsStrBin, 2);
	int bitsLen = strlen(bitsStrBin);

	int indentMark = xLen - p;
	int indent = indentMark - 1 + bitsLen + (n - bitsLen);

	printf("\nInput / Result\n");
	printf("%*s\n", indentMark, "*");
	show_ordinals(xLen);

	printf("%s\n", xStrBin);
	printf("%*s\n", indent, bitsStrBin);
}

