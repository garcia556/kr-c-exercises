#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

#define DEBUG_

void squeeze_one(char s[], int c)
{
	int i, j;
	int gotone = 0;

	for (i = j = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c && s[i+1] == c)
			continue;

		s[j++] = s[i];
	}

	s[j] = '\0';
}

void dump_array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("[%d]: %d\n", i, arr[i]);
}

void dump_array_line(int arr[], int left, int right)
{
	if (right < left)
		return;

	for (int i = left; i <= right; i++)
		printf("[%d] ", i);

	printf("\n");

	for (int i = left; i <= right; i++)
		printf(" %d  ", arr[i]);

	printf("\n");
}

/* swap_2:  interchange v[i] and v[j] */
void swap_2(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void write_level_tabs(int n)
{
	for (int i = 0; i < n; i++)
		putchar('\t');
}

/* qsort_2:  sort v[left]...v[right] into increasing order */
void qsort_2(int level, int v[], int left, int right, int leftTop, int rightTop)
{
#ifdef DEBUG
	write_level_tabs(level);
	printf("%d: calling qsort: %d - %d\n", level, left, right);
#endif

	int i, last;

	if (left >= right)   /* do nothing if array contains */
		return;          /* fewer than two elements */

#ifdef DEBUG
	dump_array_line(v, leftTop, rightTop);
#endif

	// pivot is selected as (left + right) / 2
	// moving pivot to the far left to exclude it from partitioning
	swap_2(v, left, (left + right) / 2); /* move partition elem */

#ifdef DEBUG
	write_level_tabs(level);
	printf("%d: moved pivot from the middle to far left:\n", level);
	dump_array_line(v, leftTop, rightTop);
#endif

	// last cursor is set to far left
	last = left;                     /* to v[0] */

	// looping through all the elements from the far left+1 to the end
	// kind of bubble sort: all the elements that are > pivot are being pushed to the right
	for (i = left + 1; i <= right; i++)   /* partition */
	{
#ifdef DEBUG
		write_level_tabs(level);
		printf("comparing %d [%d] < %d [%d], last == %d ...", v[i], i, v[left], left, last);
#endif

		// comparing every element to the pivot
		// if it's less - swap it with last element and advance swap cursor
		if (v[i] < v[left])
		{
#ifdef DEBUG
			printf(" ===> swapping %d [%d] and %d [%d]\n", v[last + 1], last + 1, v[i], i);
#endif

			swap_2(v, ++last, i);
		}
#ifdef DEBUG
		else
			printf("\n");
#endif
	}

#ifdef DEBUG
	write_level_tabs(level);
	printf("elements swapped, last: %d\n", last);
	dump_array_line(v, leftTop, rightTop);
#endif

	// swap pivot with last cursor dividing the partition
	swap_2(v, left, last);         /* restore partition elem */

#ifdef DEBUG
	write_level_tabs(level);
	printf("%d: moved pivot back from left to last:\n", level);
	dump_array_line(v, leftTop, rightTop);
#endif

	// sort the part to the left of the pivot
	qsort_2(level + 1, v, left, last-1, leftTop, rightTop);

	// and to the right
	qsort_2(level + 1, v, last+1, right, leftTop, rightTop);
}

////////////////////////////////////////////////

int main()
{
	int n, j, len;
	char s[1000];
	char buf[1000];
	int arr[1000];

	read_line("Enter integer array delimited by spaces", s);
	squeeze_one(s, ' ');
	len = strlen(s);

	// insert last space
	s[len] = ' ';
	s[len+1] = '\0';
	len++;

	j = 0; // char position in temporary buffer
	n = 0; // array element index
	for (int i = 0; i < len; i++)
	{
		if (s[i] != ' ')
		{
			buf[j] = s[i];
			j++;
			continue;
		}
		
		buf[j] = '\0';
		arr[n] = atoi(buf);
		n++;
		j = 0;
	}

#ifdef DEBUG
	printf("Array before sorting:\n");
	dump_array(arr, n);
	printf("\n");
#endif

	qsort_2(1, arr, 0, n - 1, 0, n - 1);

#ifdef DEBUG
	printf("\n");
#endif
	printf("Array after sorting:\n");
	dump_array(arr, n);

	return 0;
}

