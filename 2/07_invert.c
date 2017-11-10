#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

uint invert(uint x, uint p, uint n)
{
	// same as getbits
	uint xBits = (x >> (p + 1 - n)) & gen_bitmask_full(n);
	// invert & apply mask one more time to drop first unnecessary bits
	xBits = ~xBits & gen_bitmask_full(n);
	// left shift
	xBits = xBits << (p + 1 - n);

	uint xBitsPre	= (x >> (p + 1)) << (p + 1);
	uint xBitsPost	= x & gen_bitmask_full(p + 1 - n);

	return xBitsPre | xBits | xBitsPost;
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

	// p, n
	char pStr[MAX_LINE];
	char nStr[MAX_LINE];
	read_line("Enter p", pStr);
	read_line("Enter n", nStr);
	uint p = atoi(pStr);
	uint n = atoi(nStr);

	if (n > p)
		n = p + 1;

	// calc
	uint bits = invert(x, p, n);
	char bitsStrBin[MAX_LINE];
	itoa(bits, bitsStrBin, 2);
	int bitsLen = strlen(bitsStrBin);

	printf("\nInput / Result\n");
	show_ordinals(xLen);
	printf("%s\n", xStrBin);
	printf("%s\n", bitsStrBin);
}

