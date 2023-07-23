#include "main.h"
/*****************utility function****************/

/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
		return (0);
}

/**
 * append_hexa_code - Append ASCII in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @itt: Index at which to start appending.
 * @code: ASCII CODE.
 * Return: Always 3
 */
int append_hexa_code(char code, char buffer[], int itt)
{
	char point_to[] = "0123456789ABCDEF";

	if (code < 0)
		code *= -1;

	buffer[itt++] = '\\';
	buffer[itt++] = 'x';

	buffer[itt++] = point_to[code / 16];
	buffer[itt] = point_to[code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @N: Number to be casted.
 * @Z: Number indicating the type to be casted.
 *
 * Return: Casted value of N
 */
long int convert_size_number(long int N, int Z)
{
	if (Z == S_LONG)
		return (N);
	else if (Z == S_SHORT)
		return ((short)N);

	return ((int)N);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @N: Number to be casted
 * @Z: Number indicating the type to be casted
 *
 * Return: Casted value of N
 */
long int convert_size_unsgnd(unsigned long int N, int Z)
{
	if (Z == S_LONG)
		return (N);
	else if (Z == S_SHORT)
		return ((unsigned short)N);

	return ((unsigned int)N);
}

