#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "_flib.h"

int strrindex(char s[], char t[])
{
	int res = -1;

	// search from last index where there is enough length
	int is  = strlen(s) - strlen(t);
	int it  = strlen(t) - 1;
	int its = it;
	int f  = -1;
	char c;
//printf("--- start: is: %d, it: %d\n", is, it);
	while ((c = s[is--]) && (is+1) >= 0)
	{
//printf("s[%d (is)]: %c, t[%d (it)]: %c\n", is+1, c, it, t[it]);
		// found char
		if (c == t[it])
		{
			f = is + 1;
//printf("found char, f: %d\n", f);
			// search finished
			if (it == 0)
			{
//printf("FOUND ALL\n");
				break;
			}

			// advance t counter to continue search
			it--;
			continue;
		}

		// reset t counter
		it = its;
		f = -1;
	}

	if (f > -1)
		res = f;

	return res;
}

////////////////////////////////////////////////

int main()
{
	char s[MAX_LINE];
	char t[MAX_LINE];

	read_line("Enter source string"		, s);
	read_line("Enter string to search"	, t);

	int ix = strrindex(s, t);

	printf("Result:\n%d\n", ix);
}

