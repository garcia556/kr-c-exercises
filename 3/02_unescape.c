#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_flib.h"

void unescape(char s[], char t[])
{
	int is = 0;
	int it = 0;
	char c, c2;
	while ((c = s[is++]) && c != '\0')
	{
		switch (c)
		{
			case '\\':
				c2 = s[is]; // check following char
				switch (c2)
				{
					case 't':
						t[it++] = '\t';
						is++;
						break;
					case 'n':
						t[it++] = '\n';
						is++;
						break;
					default:
						t[it++] = c;
				}
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

	read_line("Enter string", s);

	unescape(s, t);

	printf("Result:\n%s\n", t);
}

