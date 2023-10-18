#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of integers
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int value = va_arg(args, int);
				printed = print_integer(value);
				count += printed;
			}
			else
			{
				_putchar('%');
				_putchar(*format);

			}

		}
	}
	va_end(args);
	return (count);
}
