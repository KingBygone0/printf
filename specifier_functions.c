#include "main.h"

/*******un-int**********/
/**
 * unsigned_int- Prints an unsigned number
 * @var_types: List of arguments
 * @buffer: Buffer array to handle print
 * @all_flags: Calculates active flags
 * @width: Get width
 * @P: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int unsigned_int(va_list var_types, char buffer[],
int all_flags, int width, int P, int size)
{
	int count = BUFFER_Z - 2;
	unsigned long int number = va_arg(var_types, unsigned long int);

	number =  convert_un_size(number, size);

	if (number == 0)
	buffer[count--] = '0';
	buffer[BUFFER_Z - 1] = '\0';
	for (; number > 0; number /= 10)
	{
	buffer[count--] = (number % 10) + '0';
	}
	count++;
	return (unsgnd(0, count, buffer, all_flags, width, P, size));
}

/********un_int_octal************/
/**
 * octal - Prints an unsigned number in octal notation
 * @var_types: List of arguments
 * @buffer: Buffer array to handle print
 * @all_flags: Calculates active flags
 * @width: Get width
 * @P: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int octal(va_list var_types, char buffer[],
int all_flags, int width, int P, int size)
{
	int count = BUFFER_Z - 2;
	unsigned long int number = va_arg(var_types, unsigned long int);
	unsigned long int initialNum = number;

	UNUSED(width);

	number = convert_un_size(number, size);

	if (number == 0)
		buffer[count--] = '0';
	buffer[BUFFER_Z - 1] = '\0';
	/* Using a do-while loop to extract octal digits from the number */
	do {
		buffer[count--] = (number % 8) + '0';
		number /= 8;
	} while (number > 0);
	/*Handling the octal prefix ('0') with the HASH_FLAG*/
	if (all_flags & HASH_FLAG && initialNum != 0)
	buffer[count--] = '0';
	count++;
	return (unsgnd(0, count, buffer, all_flags, width, P, size));
}

/*************un_int_hex********************/
/**
 * print_hex_int - Prints an unsigned number in hex notation (lowercase)
 * @var_types: List of arguments
 * @buffer: Buffer array to handle print
 * @all_flags: Calculates active flags
 * @width: Get width
 * @P: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hex_int(va_list var_types, char buffer[],
int all_flags, int width, int P, int size)
{
	return (hexa(var_types, "0123456789abcdef", buffer,
	all_flags, 'x', width, P, size));
}

/************hex_int in lower or uper*******/
/**
 * hexa - Prints an unsigned number in hexadecimal notation
 * @var_types: List of arguments
 * @hex_chars: Array of hex characters to use (e.g., "0123456789abcdef")
 * @buffer: Buffer array to handle print
 * @all_flags: Calculates active flags
 * @specifier: Hexadecimal specifier ('x' for lowercase,'x' for uppercase)
 * @width: Get width
 * @P: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexa(va_list var_types, const char *hex_chars, char buffer[],
int all_flags, char specifier, int width, int P, int size)
{
	int count = BUFFER_Z - 2;
	unsigned long int number = va_arg(var_types, unsigned long int);
	unsigned long int initialNum = number;

	UNUSED(width);
	UNUSED(P);
	UNUSED(size);

	number = convert_un_size(number, size);

	if (number == 0)
	buffer[count--] = '0';
	buffer[BUFFER_Z - 1] = '\0';
	/* Using a do-while loop to extract hexadecimal */
	/* digits from the number */
	do {
	buffer[count--] = hex_chars[number % 16];
	number /= 16;
	} while (number > 0);

    /* Handling the hexadecimal prefix ('0x' or '0X') with the HEXADECIMAL_FG*/
	if (all_flags & HEXADECIMAL_FG && initialNum != 0)
	{
	buffer[count--] = specifier;
	buffer[count--] = '0';
	}

	count++;

	return (unsgnd(0, count, buffer, all_flags, width, P, size));
}

/**********un_int num in hexa upper***********/
/**
 * Upper_hexa_only - Prints an unsigned number in upper hexadecimal notation
 * @var_types: List of arguments
 * @buffer: Buffer array to handle print
 * @all_flags: Calculates active flags
 * @width: Get width
 * @P: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int Upper_hexa_only(va_list var_types, char buffer[],
int all_flags, int width, int P, int size)
{
	return (hexa(var_types, "0123456789ABCDEF", buffer,
	all_flags, 'X', width, P, size));
}

