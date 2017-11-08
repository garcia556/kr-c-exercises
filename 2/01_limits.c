#include <stdio.h>
#include <limits.h>
#include <math.h>

#define UC  unsigned char
#define UI  unsigned int
#define USI unsigned short int
#define ULI unsigned long int

#define SC  signed char
#define SI  signed int
#define SSI signed short int
#define SLI signed long int

#define BIT_MAX 64

int main()
{
	for (int i = 1; i <= BIT_MAX; i++) {  UC x = pow(2, i); if (x <= 0) { x -= 1; printf("BITS: %02d: unsigned char      min/max: 0 / %u\n"		, i, x);			break; } }
	for (int i = 1; i <= BIT_MAX; i++) {  SC x = pow(2, i); if (x <= 0) { x -= 1; printf("BITS: %02d:   signed char      min/max: %d / %d\n"	, i, -(x+1), x);	break; } }
	for (int i = 1; i <= BIT_MAX; i++) {  UI x = pow(2, i); if (x <= 0) { x -= 1; printf("BITS: %02d: unsigned int       min/max: 0 / %u\n"		, i, x);			break; } }
	for (int i = 1; i <= BIT_MAX; i++) {  SI x = pow(2, i); if (x <= 0) { x -= 1; printf("BITS: %02d:   signed int       min/max: %d / %d\n"	, i, -(x+1), x);	break; } }
	for (int i = 1; i <= BIT_MAX; i++) { USI x = pow(2, i); if (x <= 0) { x -= 1; printf("BITS: %02d: unsigned short int min/max: 0 / %u\n"		, i, x);			break; } }
	for (int i = 1; i <= BIT_MAX; i++) { SSI x = pow(2, i); if (x <= 0) { x -= 1; printf("BITS: %02d:   signed short int min/max: %d / %d\n"	, i, -(x+1), x);	break; } }
	for (int i = 1; i <= BIT_MAX; i++) { ULI x = pow(2, i); if (x <= 0) { x -= 1; printf("BITS: %02d: unsigned long int  min/max: 0 / %lu\n"	, i, x);			break; } }
	for (int i = 1; i <= BIT_MAX; i++) { SLI x = pow(2, i); if (x <= 0) { x -= 1; printf("BITS: %02d:   signed long int  min/max: %ld / %ld\n"	, i, -(x+1), x);	break; } }
}

