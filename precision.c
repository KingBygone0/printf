#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @itt: List of arguments to be printed.
 * @var_types: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *itt, va_list var_types)
{
	int current_itt = *itt + 1;
	int P = -1;

	if (format[current_itt] != '.')
		return (P);

	P = 0;

	for (current_itt += 1; format[current_itt] != '\0'; current_itt++)
	{
		if (is_digit(format[current_itt]))
		{
			P *= 10;
			P += format[current_itt] - '0';
		}
		else if (format[current_itt] == '*')
		{
			current_itt++;
			P = va_arg(var_types, int);
			break;
		}
		else
			break;
	}

	*itt = current_itt - 1;

	return (P);
}

