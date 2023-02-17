#include <stdio.h>
#include <string.h>

/**
 * main - Prints lower and uppercase alphabets
 * Return: Always 0 (success)
 */

int main(void)
{
	char chLower = 'a';
	char chUpper = 'A';

	for (chLower = 'a'; chLower <= 'z'; chLower++)
	{
		putchar(chLower, '\n');
	}
	for (chUpper = 'A'; chUpper <= 'Z'; chUpper++)
	{
		putchar(chUpper, '\n');
	}
	return (0);
}
