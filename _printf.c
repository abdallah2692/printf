#include "main.h"
/**
 * _printf - produces output according to a format
 *
 * @format: format string
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = va_arg(args, int);

						write(1, &c, 1);
						break;
					}
				case 's':
					{
						char *s = va_arg(args, char *);

					if (s != NULL)
						write(1, s, strlen(s));
					else
						{	
							write(1, "(NULL)", 6);
						}
						break;
					}
				case'%':
					{
						write(1, "%", 1);
						break;
					}
			}
		}
		else
		{
			write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (0);
}
