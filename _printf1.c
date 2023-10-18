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
	char buffer[4096];

	va_start(args, format);

	if (format == NULL)
		return (-1);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int d = va_arg(args, int);
				int len = sprintf(buffer, "%d", d);

				write(1, buffer, len);
				count += len;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
