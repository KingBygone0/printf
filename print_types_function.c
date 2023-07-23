#include "main.h"

/************************* WRITE CHARACTERS *************************/
/**
 * write_characters - Writes characters to the buffer
 * @var_types: List of arguments
 * @buffer: Buffer array to handle write
 * @all_flags: Calculates active flags
 * @widths: Width
 * @P: Precision specification
 * @char_size: Size specifier
 * Return: Number of chars written
 */
int write_characters(va_list var_types, char buffer[],
		int all_flags, int widths, int P, int size)
{
	char c = va_arg(var_types, int);

	return (write_char(c, buffer, all_flags, widths, P, size));

}
/************************* PRINT A STRING *************************/
/**
 * strings - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int strings(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & NO_FLAGS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

		return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent_sign - Prints a percent sign
 * @var_types: List of arguments (unused)
 * @buffer: Buffer array to handle print (unused)
 * @all_flags: Calculates active flags (unused)
 * @width: Get width (unused)
 * @P: Precision specification (unused)
 * @size: Size specifier (unused)
 *
 * Return: Number of chars printed
 */
int print_percent_sign(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size)
{
	UNUSED(var_types);
	UNUSED(buffer);
	UNUSED(all_flags);
	UNUSED(width);
	UNUSED(P);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/* print interger */

/**
 * print_integer - Print int
 * @var_types: List of arguments
 * @buffer: Buffer array to handle print
 * @all_flags: Calculates active flags
 * @width: Get width.
 * @P: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_integer(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size)
{
	int count = BUFFER_Z - 2;
	int neg_Num = 0;
	long int nums = va_arg(var_types, long int);
	unsigned long int num;

	nums = size_conversion(nums, size);

	if (nums == 0)
	{
		buffer[count--] = '0';
		buffer[BUFFER_Z - 1] = '\0';
		num = (unsigned long int)nums;
	}
	if (nums < 0)
	{
		num = (unsigned long int)((-1) * nums);
		neg_Num = 1;
	}
	while (num > 0)
	{
		buffer[count--] = (num % 10) + '0';
		num /= 10;
	}
	count++;

	switch (all_flags)
	{
		case 0:
			return (write_number(neg_Num, count, buffer, NO_FLAGS, width, P, size));
		case NO_FLAGS:
			return (write_number(neg_Num, count, buffer, NO_FLAGS, width, P, size));
		default:
			return (write_number(neg_Num, count, buffer, NO_FLAGS, width, P, size));
	}
}

/* bunary */

/**
 * Binary - Prints an unsigned number in binary format
 * @var_types: List of arguments
 * @buffer: Buffer array to handle print
 * @all_flags: Calculates active flags
 * @width: Get width.
 * @P: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int Binary(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size)
{
	unsigned int n, mem, sum;
	unsigned int array[32];
	int count = 0;
	int i;
	char z;

	UNUSED(buffer);
	UNUSED(all_flags);
	UNUSED(width);
	UNUSED(P);
	UNUSED(size);

	n = va_arg(var_types, unsigned int);
	mem = 2147483648; /* (2 ^ 31) */
	array[0] = n / mem;

	i = 1;
	while (i < 32)
	{
		mem /= 2;
		array[i] = (n / mem) % 2;
		i++;
	}

	i = 0;
	sum = 0;
	while (i < 32)
	{
		sum += array[i];
		if (sum || i == 31)
		{
			z = '0' + array[i];

			write(1, &z, 1);
			count++;
	}
	i++;
	}

		return (count);
}
