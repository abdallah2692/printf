#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int _printf(const char *format, ...);
int _putchar(int c);
int print_char(va_list args);
int print_string(va_list args);
int print_per(va_list args);
void print_int(int a);
int print_dig(const char *format, ...);
#endif
