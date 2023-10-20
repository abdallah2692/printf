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
int print_integer(int value);
int _printf1(const char *format, ...);



#endif
