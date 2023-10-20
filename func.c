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
 * @args: the argument list
 * Return: number of printed integers
 */
int print_integer(va_list args)
{
	char buffer[32];
	int count = 0;
	int value = va_arg(args, int);
	int i = 0;
	int l;

	if (value < 0)
	{
		_putchar('-');
		count++;
		value = -value;
	}

	do {
		buffer[i++] = '0' + (value % 10);
		value /= 10;
		count++;
	} while (value > 0);
	for (l = i - 1; l >= 0; l--)
	{
		_putchar(buffer[l]);
	}
	return (count);
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
			_putchar(buffer[i]);
		}
	}
	*buff_ind = 0;
}

format_f funcs[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_per},
	{'d', print_integer},
	{'i', print_integer},
};
