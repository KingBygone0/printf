#include "main.h"


/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @count: Pointer to the current position in the format string
 * @list: List of arguments to be printed
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *count, va_list list)
{
	int current = *count + 1;
	int P = -1;

	if (format[current] != '.')
		return (P);

	P = 0;
	current++;

	while (numerals(format[current]))
	{
		P = P * 10 + (format[current] - '0');
		current++;
	}

	if (format[current] == '*')
	{
		current++;
		P = va_arg(list, int);
	}

		*count = current - 1;

	return (P);
}
