#include "main.h"
/**
 * print_dig - handling the i & d specifier
 * @format: format digit
 * Return: nothing
 */

void print_dig(const char *format, ...)
{
	va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'd' || *format == 'i')
            {
                print_int(va_arg(args, int));
            }
        }
        else
			putchar(*format);
        format++;
    }

    va_end(args);
}
