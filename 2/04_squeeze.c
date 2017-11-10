#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_LINE 1000

void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';
}

void squeeze_s(char s[], char sx[])
{
	for (int m = 0; sx[m] != '\0'; m++)
		squeeze(s, sx[m]);
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
	char  s[MAX_LINE];
	char sx[MAX_LINE];

	read_line(s);
	read_line(sx);

	squeeze_s(s, sx);

	printf("%s\n", s);
}

