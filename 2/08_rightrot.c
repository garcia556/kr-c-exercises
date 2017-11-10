#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

uint invert(uint x, uint n)
{
	// get n rightmost bits
	uint xBits = x & gen_bitmask_full(n);
	// invert & apply mask one more time to drop first unnecessary bits
	xBits = ~xBits & gen_bitmask_full(n);

	uint xBitsPre = (x >> (n + 1)) << (n + 1);

	return xBitsPre | xBits;
}

////////////////////////////////////////////////

int main()
{
	// x
	char xStr[MAX_LINE];
	read_line("Enter x", xStr);
	uint x = atoi(xStr);
	char xStrBin[MAX_LINE];
	itoa(x, xStrBin, 2);
	int xLen = strlen(xStrBin);
	printf("X binary: %s\n", xStrBin);

	// n
	char nStr[MAX_LINE];
	read_line("Enter n", nStr);
	uint n = atoi(nStr);

	// calc
	uint bits = invert(x, n);
	char bitsStrBin[MAX_LINE];
	itoa(bits, bitsStrBin, 2);
	int bitsLen = strlen(bitsStrBin);

	printf("\nInput / Result\n");
	show_ordinals(xLen);
	printf("%s\n", xStrBin);
	printf("%s\n", bitsStrBin);
}

