#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @var_types: List a of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{
	int itt = BUFF_SIZE - 2;
	unsigned long int N = va_arg(var_types, unsigned long int);

	N = convert_size_unsgnd(N, Z);

	if (N == 0)
		buffer[itt--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (N > 0)
	{
		buffer[itt--] = (N % 10) + '0';
		N /= 10;
	}

	itt++;

	return (write_unsgnd(0, itt, buffer, f, w, P, Z));
}


/**
 * print_octal - Prints an unsigned number in octal notation
 * @var_types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{

	int itt = BUFF_SIZE - 2;
	unsigned long int N = va_arg(var_types, unsigned long int);
	unsigned long int initial_N = N;

	UNUSED(w);

	N = convert_size_unsgnd(N, Z);

	if (N == 0)
		buffer[itt--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (N > 0)
	{
		buffer[itt--] = (N % 8) + '0';
		N /= 8;
	}

	if (f & F_HASH && initial_N != 0)
		buffer[itt--] = '0';

	itt++;

	return (write_unsgnd(0, itt, buffer, f, w, P, Z));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @var_types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{
	return (print_hexa(var_types, "0123456789abcdef", buffer,
		f, 'x', w, P, Z));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @var_types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{
	return (print_hexa(var_types, "0123456789ABCDEF", buffer,
		f, 'X', w, P, Z));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @var_types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @w: get width
 * @P: Precision specification
 * @Z: Size specifier
 * @Z: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list var_types, char map_to[], char buffer[],
	int f, char flag_ch, int w, int P, int Z)
{
	int itt = BUFF_SIZE - 2;
	unsigned long int N = va_arg(var_types, unsigned long int);
	unsigned long int initial_N = N;

	UNUSED(w);

	N = convert_size_unsgnd(N, Z);

	if (N == 0)
		buffer[itt--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (N > 0)
	{
		buffer[itt--] = map_to[N % 16];
		N /= 16;
	}

	if (f & F_HASH && initial_N != 0)
	{
		buffer[itt--] = flag_ch;
		buffer[itt--] = '0';
	}

	itt++;

	return (write_unsgnd(0, itt, buffer, f, w, P, Z));
}

