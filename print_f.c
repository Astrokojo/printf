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
			_putchar(*format);
			char_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
			break;
			if (*format == '%')
			{
				_putchar('%');
				char_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(arg, int);

				_putchar(c);
				char_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(arg, char*);
				int len_str = 0;

				while (str[len_str] != '\0')
				{
					_putchar(str[len_str]);
					len_str++;
					char_print++;
				}
			}
		}
		format++;
	}
	va_end(arg);
	return (char_print);
}
