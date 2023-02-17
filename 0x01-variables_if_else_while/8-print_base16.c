#include <stdio.h>
/**
 * main - Prints all single digit numbers of base 10
 * Return: Always 0 (success)
 */

int main(void)
{
	int num;
	char chr;

	for (num = 0; num < 10; num++)
	{
		putchar(48 + num);
	}
	for (chr = 'a'; chr <= 'f'; chr++)
	{
		putchar(chr);
	}
	putchar('\n');
	return (0);
}
