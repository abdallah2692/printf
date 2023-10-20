#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdio.h>

#define BUFF_SIZE 1024
int _printf(const char *format, ...);
int _putchar(int c);
int print_char(va_list args);
int print_string(va_list args);
int print_per(va_list args);
void print_buff(char buffer[], int *buff_ind);
int print_integer(va_list args);
int _printf1(const char *format, ...);

/**
 * format_specifiers - structure hold the format specifier and
 * the corresponding function to handle that specifier
 */
typedef struct format_specifiers
{
		char s;
		int (*function)(va_list);
} format_f;
extern format_f funcs[];


#endif
