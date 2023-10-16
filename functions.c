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
	int i = 0;
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
	while (s[i])
	{
		_putchar(s[i]);
		i++;
		count++;
	}
	return (count);

}
