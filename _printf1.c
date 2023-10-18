#include "main.h"
/**
 * _printf1 - produces output according to a format
 * @format: format string
 * Return: number of integers
 */

int _printf1(const char *format, ...)
{
	va_list args;
	int count = 0;

	int printed;

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

		}
	}
	va_end(args);
	return (count);
}
