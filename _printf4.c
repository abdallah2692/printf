#include "main.h"
/**
 * _printf4 - buffer
 * @c: char
 * Return: 1
 */


int _printf4(char c)
{
	static char buff[1024];
	static int a;

	if (c == -1 || a >= 1024)
	{
		write(1, &buff, a);
		a = 0;
	}
	if (c != -1)
	{
		buff[a] = c;
		a++;
	}
	return (1);
}
