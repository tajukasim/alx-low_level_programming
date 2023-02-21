//#include "main.h"
#include<stdio.h>
/**
 * print_times_table - Entry point
 * @n: input
 * Return: Always 0 (Success)
 */
int main(int n)
{
	int i, j;

	for (i = 0; i <= 8; i++)
	{
		for (j = 0; j <= 8; j++)
		{
			printf("%d", j*i);
			printf(", ");
		}
		printf("\n");
	}
	return (0);
}