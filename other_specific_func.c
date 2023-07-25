#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @var_types: List a of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{
	char ex_char = 0, padding = ' ';
	int buffer_indicator = BUFF_SIZE - 2, Length = 2, margin = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(var_types, void *);

	UNUSED(w);
	UNUSED(Z);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(P);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[buffer_indicator--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		Length++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padding = '0';
	if (f & F_PLUS)
		ex_char = '+', Length++;
	else if (f & F_SPACE)
		ex_char = ' ', Length++;

	buffer_indicator++;

	return (write_pointer(buffer, buffer_indicator, Length,
		w, f, padding, ex_char, margin));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @var_types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{
	int itt = 0, margin = 0;
	char *string = va_arg(var_types, char *);

	UNUSED(f);
	UNUSED(w);
	UNUSED(P);
	UNUSED(Z);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[itt] != '\0')
	{
		if (is_printable(string[itt]))
			buffer[itt + margin] = string[itt];
		else
			margin += append_hexa_code(string[itt], buffer, itt + margin);

		itt++;
	}

	buffer[itt + margin] = '\0';

	return (write(1, buffer, itt + margin));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @var_types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list var_types, char buffer[],
		int f, int w, int P, int Z)
{
	char *string;
	int itt, count = 0;

	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(Z);

	string = va_arg(var_types, char *);

	if (string == NULL)
	{
		UNUSED(P);

		string = ")Null(";
	}
	for (itt = 0; string[itt]; itt++)
		;

	for (itt = itt - 1; itt >= 0; itt--)
	{
		char ex_char = string[itt];

		write(1, &ex_char, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - Print a string in rot13.
 * @var_types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{
	char x;
	char *string;
	unsigned int itt, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(var_types, char *);
	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(P);
	UNUSED(Z);

	if (string == NULL)
		string = "(AHYY)";
	for (itt = 0; string[itt]; itt++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == string[itt])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = string[itt];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
