#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

void escape(char s[], char t[])
{
	int is = 0;
	int it = 0;
	char c;
	while ((c = s[is++]) && c != '\0')
	{
		switch (c)
		{
			case '\n':
				t[it++] = '\\';
				t[it++] = 'n';
				break;
			case '\t':
				t[it++] = '\\';
				t[it++] = 't';
				break;
			default:
				t[it++] = c;
		}
	}

	t[it] = '\0';
}

////////////////////////////////////////////////

int main()
{
	char s[MAX_LINE];
	char t[MAX_LINE];

	read_line_n("Enter string (use Ctrl+D to stop)", s);

	escape(s, t);

	printf("Result:\n%s\n", t);
}

