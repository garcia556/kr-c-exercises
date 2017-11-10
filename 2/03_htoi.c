#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_LINE 1000
#define BASE_HEX 16
#define BASE_DEC 10

int c_hex_valid(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c == 'x'));
}

int c_hex_to_dec(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';

	if (c >= 'a' && c <= 'f')
		return c - 'a' + BASE_DEC;

	return 0;
}

int main()
{
	char c;
	char s[MAX_LINE];
	int res = 0, i;

	for (i = 0; i < MAX_LINE - 1 && (c = tolower(getchar())) && c != '\n' && c != EOF; i++)
	{
		// input validation
		if (!c_hex_valid(c))
		{
			printf("ERROR! Not a valid character: %c\n", c);
			return 1;
		}

		s[i] = c;
	}
	s[i] = '\0';

	// skip optional 0x in the beginning
	int start = 0;
	if (s[0] == '0' && s[1] == 'x')
		start = 2;

	for (int k = start; k < i + start; ++k)
		res += c_hex_to_dec(s[k]) * pow(BASE_HEX, i - k - 1);

	printf("Decimal result: %d\n", res);
}

