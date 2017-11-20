#include <stdio.h>
#include <string.h>
#include "_flib.h"

#define STR_SIZE 1000
#define TABSIZE 8

void print_spaces()
{
	for (int i = 0; i < TABSIZE; i++)
		putchar(' ');
}

int is_tabstop(char c, char *lib[], int libsize)
{
	for (int i = 0; i < libsize; i++)
	{
		if (*lib[0] == c)
			return 1;
		lib++;
	}

	return 0;
}

/* print longest input line; specialized version */
int main(int argc, char *argv[])
{
	// set default tabstop
	if (argc == 1)
		*argv = "\t";
	else
	{
		argv++;
		argc--;
	}

	char s[STR_SIZE];
	while (1)
	{
		read_line("Enter string", s);
		if (s[0] == '\0')
		{
			printf("\n");
			break;
		}

		int len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			if (is_tabstop(s[i], argv, argc))
				print_spaces();
			else
				putchar(s[i]);
		}
		putchar('\n');
	}

	return 0;
}

