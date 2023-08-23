#include "main.h"
/**
* print_char - Print a character and update character count.
* @c: a character
* @char_print: prints a character
* Return: c
*/
int print_char(char c, int *char_print)
{
	    _putchar(c);
	    (*char_print)++;
		return (c);
}

/**
* print_string - Print a string and update character count.
* @str: a string pointer
* @char_print: prints a character
* Return: i
*/
int print_string(char *str, int *char_print)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		(*char_print)++;
	}
	return (i);
}
/**
* print_integer - Print an integer and update character count.
* @num: an integer pointer
* @char_print: prints a character
* Return: num
*/
int print_integer(int num, int *char_print)
{
		char num_str[12];

		sprintf(num_str, "%d", num);
		return (print_string(num_str, char_print));
}
/**
* print_binary - Prints an unsigned int into binary
* @dig: unsigned int variable
* @char_print: prints characters
* Return: int
*/
int print_binary(unsigned int dig, int *char_print)
{
	char bin_str[33];
	int index = 0;
	int i;

	if (dig == 0)
		bin_str[index++] = '0';
	else
	{
		while (dig > 0)
		{
			bin_str[index++] = (dig % 2) + '0';
			dig /= 2;
		}
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(bin_str[i]);
		(*char_print)++;
	}
	return (index);
}
/**
*  _printf - a funtion that produces output according to format
* @format: a character string
* Return: length of a string or -1
*/
int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list arg;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (*format)
	{
		if (*format != '%')
		{
			print_char(*format, &char_print);
		}
		else
		{
			format++;
			while (*format == ' ')
				format++;
			if (*format == '\0')
				return (-1);
			if (*format == '%')
			{
				print_char('%', &char_print);
			}
			else if (*format == 'c')
				print_char(va_arg(arg, int), &char_print);

			else if (*format == 's')
				print_string(va_arg(arg, char*), &char_print);

			else if (*format == 'd' || *format == 'i')
				print_integer(va_arg(arg, int), &char_print);

			else if (*format == 'b')
				print_binary(va_arg(arg, unsigned int), &char_print);
		}
		format++;
	}
	va_end(arg);
	return (char_print);
}
