#include <stdio.h>

#define USINT unsigned short int

int main()
{
	int x = 1, y = 2, z[10];
	int* ip;         /* ip is a pointer to int */
	USINT* sp;

	ip = &x;         /* ip now points to x */
	printf("Set value to x: %d (%p)\n", *ip, ip);

	y = *ip;         /* y is now 1 */
	*ip = 0;         /* x is now 0 */
	printf("Set value to 0: %d (%p)\n", *ip, ip);

	z[0] = 0x0fffdead;
	ip = &z[0];      /* ip now points to z[0] */
	printf("Set pointer to array[0]: %d (%p)\n", *ip, ip);

	sp = (USINT*)(&z[0]);
	printf("sp: %d / 0x%04x (%p)\n", *sp, *sp, sp);

	// check endianness
	// big endian branch can be checked using MIPS emulator: https://people.debian.org/~aurel32/qemu/mips/
	int e = 1;
	char* c = (char*)&e;
	printf("c: 0x%02x\n", *c);

	if (*c == 1)
		printf("litte endian (intel style)\n");
	else
		printf("big endian\n");
}

