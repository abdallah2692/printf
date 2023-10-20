#include <stdarg.h>  // For handling variadic arguments
#include <stdio.h>   // For standard input/output

int print_integer(int value);
void print_buffer(char buffer[], int *buff_ind);

#define BUFF_SIZE 1024

int _printf(const char *format, ...)
{
    va_list args;      // Declare a variable to hold the list of arguments
    int count = 0;     // Initialize a counter for the number of characters printed
    int printed = 0;   // Number of characters printed by each conversion specifier
    int buff_ind = 0;  // Buffer index
    char buffer[BUFF_SIZE];

    va_start(args, format); // Initialize the argument list

    while (*format) // Iterate over each character in the format string
    {
        if (*format == '%') // Check for the start of a conversion specifier
        {
            format++; // Move to the next character after '%'

            if (*format == '%') // Case: '%%' prints a single '%'
            {
                buffer[buff_ind++] = '%';
                if (buff_ind == BUFF_SIZE)
                {
                    print_buffer(buffer, &buff_ind);
                    count += buff_ind;
                }
            }
            else if (*format == 'c') // Case: '%c' prints a character
            {
                int ch = va_arg(args, int); // Fetch the next argument as int
                buffer[buff_ind++] = ch;
                if (buff_ind == BUFF_SIZE)
                {
                    print_buffer(buffer, &buff_ind);
                    count += buff_ind;
                }
            }
            else if (*format == 's') // Case: '%s' prints a string
            {
                char *str = va_arg(args, char *); // Fetch the next argument as char*
                while (*str) // Iterate over each character in the string
                {
                    buffer[buff_ind++] = *str;
                    str++;
                    if (buff_ind == BUFF_SIZE)
                    {
                        print_buffer(buffer, &buff_ind);
                        count += buff_ind;
                    }
                }
            }
            else if (*format == 'd' || *format == 'i') // Case: '%d' or '%i' prints an integer
            {
                int value = va_arg(args, int);
                printed = print_integer(value);
                count += printed;
            }
        }
        else // Case: Regular character, not a conversion specifier
        {
            buffer[buff_ind++] = *format;
            if (buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, &buff_ind);
                count += buff_ind;
            }
        }

        format++; // Move to the next character in the format string
    }

    print_buffer(buffer, &buff_ind);
    count += buff_ind;

    va_end(args); // Clean up the argument list

    return count; // Return the number of characters printed
}

int print_integer(int value)
{
    // Convert the integer to a string representation and print it
    char buffer[32];
    int printed = snprintf(buffer, sizeof(buffer), "%d", value);
    for (int i = 0; i < printed; i++)
    {
        putchar(buffer[i]);
    }
    return printed;
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        for (int i = 0; i < *buff_ind; i++)
        {
            putchar(buffer[i]);
        }
    }

    *buff_ind = 0;
}
