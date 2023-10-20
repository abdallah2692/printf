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
	int i = 0;
	int j = 0;

	va_start(args, format);

	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{	_putchar(format[i]);
			count++;
			i++;
		}
		else
		{
			while (functions[j].s)
			{
				if (format[i + 1] == functions[j].s)
				{
					count += functions[j].function(args);
				}
				j++;
			}
			i += 2;
		}
	}
	va_end(args);
	return (count);
}
