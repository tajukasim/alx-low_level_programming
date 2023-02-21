#include "main.h"
#include<stdio.h>
/**
 * print_times_table - Entry point
 * @n: input
 * Return: Always 0 (Success)
 */
void print_times_table(int n)
{
	int i, j;

	for (i = 0; i <= n; i++)
	{
		for j = 0; j <= n; j++)
			printf("%d", i * j);

	return (0);
}
