#include "main.h"
/**
 * _putchar - write character to stdout
 * @c: character to write
 * Return: write with number and character
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}
