#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @count: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Width.
 */
int get_width(const char *format, int *count, va_list list)
{
	int current = *count + 1;
	int width = 0;

	while (format[current] != '\0')
	{
		char c = format[current];

		if (c >= '0' && c <= '9')
		{
			width *= 10;
			width += c - '0';
			current++;
		}
		else if (c == '*')
		{
			current++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

		*count = current - 1;

		return (width);
}
