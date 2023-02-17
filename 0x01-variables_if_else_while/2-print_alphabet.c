#include <stdio.h>
#include <string.h>

/**
 * main - Prints lower and uppercase alphabets
 * Return: Always 0 (success)
 */

int main(void)
{
	char chLower = 'a';

	for (chLower = 'a'; chLower <= 'z'; chLower++)
	{
		putchar(chLower);
		putchar('\n')
	}
	return (0);
}
