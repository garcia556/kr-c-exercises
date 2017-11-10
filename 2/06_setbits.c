#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

unsigned int setbits(uint x, int p, int n, uint y)
{
/*
~0							: all 1
~0 << n						: make n rightmost bits as 0
~(~0 << n)					: convert n rightmost bits to 1 to create a mask
y & ~(~0 << n)				: apply mask to get n rightmost bits of y
(y & ~(~0 << n)) << (p - 1)	: shift to p position of x
x | ...						: set bits to x
*/
	uint yBits		= (y & gen_bitmask_full(n)) << (p - 1);
	uint xBitsPre	= (x >> (p + 1)) << (p + 1);
	uint xBitsPost	= x & gen_bitmask_full(p + 1 - n);

	return xBitsPre | yBits | xBitsPost;
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

	// x
	char yStr[MAX_LINE];
	read_line("Enter y", yStr);
	int y = atoi(yStr);
	char yStrBin[MAX_LINE];
	itoa(y, yStrBin, 2);
	int yLen = strlen(yStrBin);
	printf("Y binary: %s\n", yStrBin);

	// calc
	int bits = setbits(x, p, n, y);
	char bitsStrBin[MAX_LINE];
	itoa(bits, bitsStrBin, 2);
	int bitsLen = strlen(bitsStrBin);

	printf("\nInput X, Y / Result\n");
	printf("%s\n", xStrBin);
	printf("%s\n", yStrBin);
	printf("%s\n", bitsStrBin);
}

