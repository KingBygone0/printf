 #include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @itt: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *itt)
{
	int current_itt = *itt + 1;
	int Z = 0;

	if (format[current_itt] == 'l')
		Z = S_LONG;
	else if (format[current_itt] == 'h')
		Z = S_SHORT;

	if (Z == 0)
		*itt = current_itt - 1;
	else
		*itt = current_itt;

	return (Z);
}
