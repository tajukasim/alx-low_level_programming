#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char _putchar(char c)
{
	return (write(1, &c, 1));
}

void _puts(char *c)
{
	int i = 0;
	while(*(c + i) != '\0')
	{
        _putchar(*(c + i));
        i ++;
	}
}
int len(const char *c)
{
	int i = 0;
	while(*(c + i) != '\0')
	{
		i ++;
	}
	return i;
}

