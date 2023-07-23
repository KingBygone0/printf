#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @count: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *count)
{
	int current = *count + 1;
	int size = 0;

	switch (format[current])
	{
		case 'l':
			size = LONG_STRING;
			break;
		case 'h':
			size = SHORT_STRING;
			break;
			default:
			*count = current - 1;
			break;
	}

	if (size != 0)
	{
		*count = current;
	}
		return (size);
}
