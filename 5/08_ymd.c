#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_flib.h"

#define SIZE 1000

#define MONTHS 13
static char LIB[2][MONTHS] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 1;
}

int day_count(int year)
{
	int days;

	int leap = is_leap(year);
	days = 0;
	for (int i = 0; i < MONTHS; i++)
		days += LIB[leap][i];

	return days;
}

/* day_of_year:  set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = is_leap(year);
	for (i = 1; i < month; i++)
		day += LIB[leap][i];
	return day;
}

/* month_day:  set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = is_leap(year);
	for (i = 1; yearday > LIB[leap][i]; i++)
		yearday -= LIB[leap][i];
	*pmonth = i;
	*pday = yearday;
}

////////////////////////////////////

int yd()
{
	int year, month, day, res, leap, days_m;
	char s[SIZE];
	char msg[SIZE];

	read_line("Enter year", s);
	year = atoi(s);
	if (year < 0)
	{
		printf("Invalid year\n");
		return 1;
	}
	leap = is_leap(year);

	sprintf(msg, "Enter month (1-%d)", MONTHS - 1);
	read_line(msg, s);
	month = atoi(s);
	if (month < 1 || month >= MONTHS)
	{
		printf("Invalid month\n");
		return 2;
	}
	days_m = LIB[leap][month];

	sprintf(msg, "Enter day (1-%d)", days_m);
	read_line(msg, s);
	day = atoi(s);
	if (day < 1 || day > days_m)
	{
		printf("Invalid day\n");
		return 3;
	}

	res = day_of_year(year, month, day);

	printf("Result: %d\n", res);

	return 0;
}

int md()
{
	int year, yearday, month, day, days_y;
	char s[SIZE];
	char msg[SIZE];

	read_line("Enter year", s);
	year = atoi(s);
	if (year < 0)
	{
		printf("Invalid year\n");
		return 1;
	}
	days_y = day_count(year);

	sprintf(msg, "Enter day (1-%d)", days_y);
	read_line(msg, s);
	yearday = atoi(s);
	if (yearday < 1 || yearday > days_y)
	{
		printf("Invalid day\n");
		return 2;
	}

	month_day(year, yearday, &month, &day);

	printf("Result (month / day): %d / %d\n", month, day);

	return 0;
}

int main()
{
	char s[SIZE];

	int mode;
	read_line("Would you like to calculate 1) day of year or 2) month day", s);
	mode = atoi(s);

	if (mode == 1)
		return yd();
	else
	if (mode == 2)
		return md();
	else
		printf("Sorry didn't get you\n");

	return 1;
}

