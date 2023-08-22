#include "main.h"
#include <stdlib.h>

/**
 * print_int - prints an integer
 * @number: number to be printed
 * @count: pointer to count number of characters printed
 */
void print_int(int number, void *count)
{
	unsigned int n = number;

	if (number < 0)
	{
		_putchar('-', count);
		n = -number;
	}
	if (n < 10)
		_putchar(n + '0', count);
	else
	{
		print_int(n / 10, count);
		print_int(n % 10, count);
	}
}
