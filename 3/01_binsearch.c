#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (v[mid] != x && low <= high)
	{
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;

		mid = (low + high) / 2;
	}

	if (v[mid] == x)
		return mid;

	return -1;    /* no match */
}

////////////////////////////////////////////////

int main()
{
	char s[MAX_LINE];
	char msg[MAX_LINE];

	read_line("Enter array size", s);
	int size = atoi(s);

	int arr[size];
	for (int i = 0; i < size; ++i)
	{
		sprintf(msg, "Enter %d element", i);
		read_line(msg, s);
		arr[i] = atoi(s);
	}

	read_line("Enter number to be searched", s);
	int x = atoi(s);

	int res = binsearch(x, arr, size);

	printf("\nResult: %d\n", res);
}

