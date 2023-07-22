#include "main.h"

/**
 * numerals - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int numerals(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

#include "main.h"

/**
 * size-conversion - Casts a number to the specified type
 * @number: Number to be casted.
 * @size: Type indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int size_conversion(long int number, int size)
{
	switch (size)
	{
		case LONG_STRING:
			return (number);
		case SHORT_STRING:
			return ((short)number);
		default:
			return ((int)number);
	}
}

/**
 * convert_un_size - Casts an unsigned number to the specified type
 * @number: Number to be casted.
 * @size: Type indicating the type to be casted.
 *
 * Return: Casted value of num
 */
unsigned long int convert_un_size(unsigned long int number, int size)
{
	switch (size)
	{
		case LONG_STRING:
			return (number);
		case SHORT_STRING:
			return ((unsigned short)number);
		default:
			return ((unsigned int)number);
	}
}

/**
 * hexa_append - Appends a hexadecimal representation of
 * a character to the buffer
 * @ch: The character to represent in hexadecimal
 * @buffer: Buffer array to handle print
 * @index: The index to append the hexadecimal representation
 * Return: Number of characters appended to the buffer
 */
int hexa_append(char ch, char buffer[], int index)
{
	char hex_digits[] = "0123456789ABCDEF";

	buffer[index] = HEXA_PREFIX[0];
	buffer[index + 1] = hex_digits[(ch >> 4) & 0xF];
	buffer[index + 2] = hex_digits[ch & 0xF];
	return (3); /* 3 characters appended to the buffer for "\xhh" */
}

/**
 * printable - Checks if a character is printable (ASCII code 32 to 126)
 * @ch: The character to check
 * Return: 1 if printable, 0 otherwise
 */
int printable(char ch)
{
	return (ch >= 32 && ch <= 126);
}
