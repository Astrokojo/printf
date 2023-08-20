#include "main.h"

/**
* print_char - Print a character and update character count.
* @c: a character
* @char_print: prints a character
*/
static void print_char(char c, int *char_print)
{
	    _putchar(c);
	    (*char_print)++;
}

/**
* print_string - Print a string and update character count.
* @str: a string pointer
* @char_print: prints a character
*/
static void print_string(char *str, int *char_print)
{
	int i = 0;

	while (str[i] != '\0')
	{
	    _putchar(str[i]);
	    (*char_print)++;
		i++;
	}
}

#include "main.h"
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
			if (*format == '\0')
			break;
			if (*format == '%')
			{
				print_char('%', &char_print);
			}
			else if (*format == 'c')
			{
				char c = va_arg(arg, int);

				print_char(c, &char_print);
			}
			else if (*format == 's')
			{
				char *str = va_arg(arg, char*);

				print_string(str, &char_print);
			}
		}
		format++;
	}
	va_end(arg);
	return (char_print);
}