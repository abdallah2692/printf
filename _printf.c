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
	if (format == NULL)
		return (-1);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				va_end(args);
				return (-)1;
			}
			else if (*format == 'c') count += print_char(va_arg(args, int));
			else if (*format == 's') count += print_string(va_arg(args, char *));
			else if (*format == '%') count += print_per(args);
			else if (*format == 'd' || *format == 'i')
			{
				count += print_integer(va_arg(args, int));
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
	}

	va_end(args);
	return (count);
}
