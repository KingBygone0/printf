#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @count: Pointer to the current position in the format string
 *
 * Return: All flags combined.
 */
int get_flags(const char *format, int *count)
{
	int all_flags = 0;
	int current = *count + 1;

	while (format[current] != '\0')
	{
		switch (format[current])
	{
		case '-':
			all_flags |= NO_FLAGS;
		break;
		case '+':
			all_flags |= ADD_FLAGS;
		break;
		case '0':
			all_flags |= ZERO_FLAGS;
		break;
		case '#':
			all_flags |= HASH_FLAG;
		break;
		case ' ':
			all_flags |= SPACE;
		break;
		default:
			return (all_flags);
	}
	current++;
	}

		*count = current - 1;

	return (all_flags);
}
