#include <stdio.h>
#include <limits.h>
#include <math.h>

#define I   int

#define UC  unsigned char
#define UI  unsigned int
#define USI unsigned short int
#define ULI unsigned long int

#define SC  signed char
#define SI  signed int
#define SSI signed short int
#define SLI signed long int

#define BIT_MAX 128

int main()
{
	for (int i = 1; i <= BIT_MAX; i*=2) {   I x = pow(2, i-1);	if (x <= 0) { x -= 1; printf("BITS: %02d:          int       min/max: %d / %d\n"	, i, -(x+1), x);	break; } }
	for (int i = 1; i <= BIT_MAX; i*=2) {  UC x = pow(2, i);	if (x <= 0) { x -= 1; printf("BITS: %02d: unsigned char      min/max: 0 / %u\n"		, i, x);			break; } }
	for (int i = 1; i <= BIT_MAX; i*=2) {  SC x = pow(2, i-1);	if (x <= 0) { x -= 1; printf("BITS: %02d:   signed char      min/max: %d / %d\n"	, i, -(x+1), x);	break; } }
	for (int i = 1; i <= BIT_MAX; i*=2) {  UI x = pow(2, i);	if (x <= 0) { x -= 1; printf("BITS: %02d: unsigned int       min/max: 0 / %u\n"		, i, x);			break; } }
	for (int i = 1; i <= BIT_MAX; i*=2) {  SI x = pow(2, i-1);	if (x <= 0) { x -= 1; printf("BITS: %02d:   signed int       min/max: %d / %d\n"	, i, -(x+1), x);	break; } }
	for (int i = 1; i <= BIT_MAX; i*=2) { USI x = pow(2, i);	if (x <= 0) { x -= 1; printf("BITS: %02d: unsigned short int min/max: 0 / %u\n"		, i, x);			break; } }
	for (int i = 1; i <= BIT_MAX; i*=2) { SSI x = pow(2, i-1);	if (x <= 0) { x -= 1; printf("BITS: %02d:   signed short int min/max: %d / %d\n"	, i, -(x+1), x);	break; } }
	for (int i = 1; i <= BIT_MAX; i*=2) { ULI x = pow(2, i);	if (x <= 0) { x -= 1; printf("BITS: %02d: unsigned long int  min/max: 0 / %lu\n"	, i, x);			break; } }
	for (int i = 1; i <= BIT_MAX; i*=2) { SLI x = pow(2, i-1);	if (x <= 0) { x -= 1; printf("BITS: %02d:   signed long int  min/max: %ld / %ld\n"	, i, -(x+1), x);	break; } }
}

