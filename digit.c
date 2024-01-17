#include "monty.h"

/**
 * is_number - Checks if a string represents a valid integer.
 * @str: String to check.
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_number(char *str)
{
    int has_digits;

    if (*str == '-' || *str == '+')
        str++;

    has_digits = 0;

    while (*str)
    {
        if (!isdigit(*str))
            return 0;

        has_digits = 1;
        str++;
    }

    return has_digits;
}
