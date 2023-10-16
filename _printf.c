#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: format string
 *
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
				_putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				int c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (s != NULL && *s != '\0')
				{
					_putchar(*s);
					count++;
					s++;
				}
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
