#include "main.h"
/****************** PRINT POINTER ******************/
/**
 * Pointers - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int Pointers(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFFER_Z - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
	return (write(1, "(nil)", 5));

	buffer[BUFFER_Z - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	do {
	buffer[ind--] = map_to[num_addrs % 16];
	num_addrs /= 16;
	length++;
	} while (num_addrs > 0);

	if ((flags & ZERO_FLAGS) && !(flags & NO_FLAGS))
	padd = '0';
	if (flags & ADD_FLAGS)
	extra_c = '+', length++;
	else if (flags & SPACE)
	extra_c = ' ', length++;

	ind++;

    /*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
			width, flags, padd, extra_c, padd_start));
}


/**********unprintable*********/
/**
 * not_Printable - Prints ASCII codes in hexa of non-printable characters
 * @var_types: List of arguments
 * @buffer: Buffer array to handle print
 * @all_flags: Calculates active flags
 * @width: Get width
 * @P: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int not_Printable(va_list var_types, char buffer[],
	int all_flags, int width, int P, int size)
{
	int i = 0, prefix = 0;
	char *string = va_arg(var_types, char *);

	UNUSED(all_flags);
	UNUSED(width);
	UNUSED(P);
	UNUSED(size);

	if (string == NULL)
	return (write(1, "(null)", 6));

	while (string[i] != '\0')
	{
	if (printable(string[i]))
	buffer[i + prefix] = string[i];
	else
	prefix += hexa_append(string[i], buffer, i + prefix);
	i++;
	}

	buffer[i + prefix] = '\0';

	return (write(1, buffer, i + prefix));
}

/********print in reverse**********/

/**
 * Reverse - Prints a reversed string.
 * @var_types: List of arguments
 * @buffer: Buffer array to handle print
 * @all_flags: Calculates active flags
 * @width: Get width
 * @P: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int Reverse(va_list var_types, char buffer[],
	int all_flags, int width, int P, int size)
{
	char *string;
	int i, count = 0;
	char z;

	UNUSED(buffer);
	UNUSED(all_flags);
	UNUSED(width);
	UNUSED(size);
	string = va_arg(var_types, char *);
	if (string == NULL)
	{
	UNUSED(P);

	string = ")Null(";
	}

	for (i = 0; string[i]; i++)
	;

	for (i = i - 1; i >= 0; i--)
	{
	z = string[i];

	write(1, &z, 1);
	count++;
	}

	return (count);
}

/************8string in rot13*************/

/**
 * Rot13string - Print a string in rot13.
 * @var_types: List of arguments
 * @buffer: Buffer array to handle print
 * @all_flags: Calculates active flags
 * @width: Get width
 * @P: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int Rot13string(va_list var_types, char buffer[],

	int all_flags, int width, int P, int size)
{
	char r;
	char *string;
	unsigned int i = 0, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(var_types, char *);
	UNUSED(buffer);
	UNUSED(all_flags);
	UNUSED(width);
	UNUSED(P);
	UNUSED(size);

	if (string == NULL)
	string = "(AHYY)";

	while (string[i])
	{
	j = 0;
	while (in[j])
	{
		if (in[j] == string[i])
		{
		r = out[j];
		write(1, &r, 1);
		count++;
		break;
	}
	j++;
	}
	if (!in[j])
	{
		r = string[i];
		write(1, &r, 1);
		count++;
	}
	i++;
	}
	return (count);
}
