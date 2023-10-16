#include "main.h"
#include <stdio.h>
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
				fputc('%', stdout);
				count++;
			}
			else if (*format == 'c')
			{
				count += print_char(args);
			}
			else if (*format == 's')
			{
				count += print_string(args);
			}
		}
		else
		{
			fputc(*format);
			count++;
		}
			format++;
	}
		va_end(args);
		return (count);
}
