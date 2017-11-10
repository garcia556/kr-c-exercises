#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

int bitcount(uint x)
{
	int b = 0;

	// iteration count is 1-bit count
	// in slower version loop count = total bit count
	while (x != 0)
	{
		x &= (x - 1);
		b++;
	}

	return b;
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

	// calc
	int res = bitcount(x);

	printf("\nInput / Result\n");
	printf("%s, bit count: %d\n", xStrBin, res);
}

