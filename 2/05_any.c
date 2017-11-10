#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_LINE 1000

int any(char s[], char c)
{
	int res = -1;

	for (int i = 0; s[i] != '\0'; ++i)
		if (s[i] == c)
		{
			res = i;
			break;
		}

	return res;
}

int any_s(char s1[], char s2[])
{
	int res = -1;

	for (int i = 0; s2[i] != '\0'; ++i)
	{
		int resc = any(s1, s2[i]);
		if (resc > res)
			res = resc;
	}

	return res;
}

void read_line(char s[])
{
	char c;
	int i;
	for (i = 0; i < MAX_LINE - 1 && (c = getchar()) && c != '\n' && c != EOF; i++)
		s[i] = c;
	s[i] = '\0';
}

int main()
{
	char s1[MAX_LINE];
	char s2[MAX_LINE];

	read_line(s1);
	read_line(s2);

	int pos = any_s(s1, s2);

	printf("%d\n", pos);
}

