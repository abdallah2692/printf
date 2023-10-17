#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: the number of characters printed
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
			if (*format == '%')
			{
				count += print_per(args);
			}
			else if (*format == 'c')
			{
				count += print_char(args);
			}
			else if (*format == 's')
			{
				count += print_string(args);
			}
			else if (*format == '\0')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int digit = va_arg(args, int);
				count += print_int(digit);
			}
			else if (*format == 'u')
			{
				unsigned int a = va_arg(args, unsigned int);
				count += print_unsi(a);
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
