#include <stdio.h>
/**
 * main - Prints all single digit numbers of base 10
 * Return: Always 0 (success)
 */

int main(void)
{
	int n;

	for (n = '0'; n <= '9'; n++)
	{
	putchar(n);
	if (n != '9')
	{
	putchar(',');
	putchar(' ');
	}
	}
	putchar('\n');
	return (0);
}
