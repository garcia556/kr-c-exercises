#include <stdio.h>

//#define QUOTE_CHAR '\''
#define QUOTE_STRING '"'

#define COMMENT_1        '/'
#define COMMENT_2_SINGLE '/'
#define COMMENT_2_MULTI  '*'

#define IN  1
#define OUT 0

#define SINGLE 2
#define MULTI  3

int main()
{
	int c, pprev, prev;
	int status_comment = OUT;
	int status_string = OUT;

	pprev = -1;
	prev = -1;
	while ((c = getchar()) != EOF)
	{
		// string handling
		if (c == QUOTE_STRING)
		{
			if (status_string == IN)
				status_string = OUT;
			else
			if (status_string == OUT)
				status_string = IN;
		}

		// possible start of comment
		if (status_comment == OUT && c == COMMENT_1)
			status_comment = IN;

		if (prev == COMMENT_1)
		{
			if (c == COMMENT_2_SINGLE)
				status_comment = SINGLE;
			else
			if (c == COMMENT_2_MULTI)
				status_comment = MULTI;
			else
			// possible start of comment did not work out
			if (status_comment == IN)
				status_comment = OUT;
		}

		if (status_comment == SINGLE && c == '\n')
			status_comment = OUT;

		if (status_comment == MULTI && prev == COMMENT_1 && pprev == COMMENT_2_MULTI)
			status_comment = OUT;

		if (status_comment == OUT || status_string == IN)
			putchar(c);

		pprev = prev;
		prev = c;
	}

	return 0;
}

