#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @itt: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *itt)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int EN, curr_i;
	int f = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *itt + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (EN = 0; FLAGS_CH[EN] != '\0'; EN++)
			if (format[curr_i] == FLAGS_CH[EN])
			{
				f |= FLAGS_ARR[EN];
				break;
			}

		if (FLAGS_CH[EN] == 0)
			break;
	}

	*itt = curr_i - 1;

	return (f);
}
