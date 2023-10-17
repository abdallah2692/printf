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
/**
 * print_integer - for printing integers
 * @value: the entered value
 * Return: number of printed integers
 */
int print_integer(int value)
{
	int i = 0;
	int l;
	char buffer[32];
	int printed = 0;

	if (value < 0)
	{
		putchar('-');
		printed++;
		value = -value;
	}

	do {
		buffer[i++] = '0' + (value % 10);
		value /= 10;
		printed++;
	} while (value > 0);
	for (l = i - 1; l >= 0; l--)
	{
		putchar(buffer[l]);
	}
	return (printed);
}

/**
 * print_buffer - prints the contents of a buffer and
 * then resets the buffer index to 0
 * @buffer: character array
 * @buff_ind: integar pointer
 * Return: void
 */
void print_buffer(char buffer[], int *buff_ind)
{
	int i;

	if (*buff_ind > 0)
	{
		for (i = 0; i < *buff_ind; i++)
		{
			putchar(buffer[i]);
		}
	}
	*buff_ind = 0;
}


