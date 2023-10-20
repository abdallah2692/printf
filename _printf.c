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
	int l;

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
			l = 0;
			while (funcs[l].s)
			{
				if (format[i + 1] == funcs[l].s)
					count += funcs[l].function(args);
				l++;
			}
			i += 2;
		}
	}
	va_end(args);
	return (count);
}
