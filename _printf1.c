#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of integers
 */

#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of integers
 */

int _printf(const char *format, ...)
{
	int count = 0;
	int pri = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int val = va_arg(args, int);
				pri = print_int(val);
				count += pri;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
			}
			format++;
		}
		else
		{
			_putchar(*format);
			format++;
		}
	}

	va_end(args);
	return (count);
}
