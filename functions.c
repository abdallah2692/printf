#include "main.h"
/**
 * print_char - prints a char
 * @args: arguments list
 * Return: 1
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	int count = 0;

	_putchar(c);
	count++;
	return (count);
}
/**
 * print_string - prints a string
 * @args: arguments list
 * Return: number of printer characters
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char*);
	int count = 0;

	if (s == NULL)
	{
		_putchar ('(');
		_putchar ('n');
		_putchar ('u');
		_putchar ('l');
		_putchar ('l');
		_putchar (')');
		return (6);
	}
	else
	{
		for (; *s; ++s)
		{
			_putchar(*s);
			count++;
		}
	}
	return (count);
}
/**
 * print_per - prints %
 * @args: the argument list
 * Return: 1
 */
int print_per(va_list args)
{
	int count = 0;

	(void)args;
	_putchar ('%');
	count++;
	return (1);
}

