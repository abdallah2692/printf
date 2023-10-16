#include "main.h"
/**
 * print_char - prints a char
 *
 * @args: arguments list
 */
void print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
}
/**
 * print_string - prints a string
 *
 *@args: arguments list
 */
void print_string(va_list args)
{
	char *s = va_arg(args, char*);

	if (s == NULL)
		s = "      ";
	for (; *s; ++s)
	{
		_putchar(*s);
	}
}
