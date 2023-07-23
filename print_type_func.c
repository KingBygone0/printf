#include "main.h"

/**
 * print_char - Prints a char
 * @var_types: List a of arguments
 * @buffer: Buffer array to handle print
 * @f: Calculates active flags
 * @w: Width
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{
	char c = va_arg(var_types, int);

	return (handle_write_char(c, buffer, f, w, P, Z));
}

/**
 * print_string - Prints a string
 * @var_types: List a of arguments
 * @buffer: Buffer array to handle print
 * @f: Calculates active flags
 * @w: get width.
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{
	int Length = 0, itt;
	char *string = va_arg(var_types, char *);

	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(P);
	UNUSED(Z);
	if (string == NULL)
	{
		string = "(null)";
		if (P >= 6)
			string = "      ";
	}

	while (string[Length] != '\0')
		Length++;

	if (P >= 0 && P < Length)
		Length = P;

	if (w > Length)
	{
		if (f & F_MINUS)
		{
			write(1, &string[0], Length);
			for (itt = w - Length; itt > 0; itt--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (itt = w - Length; itt > 0; itt--)
				write(1, " ", 1);
			write(1, &string[0], Length);
			return (w);
		}
	}

	return (write(1, string, Length));
}

/**
 * print_percent - Prints a percent sign
 * @var_types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f: Calculates active flags
 * @w: get width.
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{
	UNUSED(var_types);
	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(P);
	UNUSED(Z);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @var_types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f: Calculates active flags
 * @w: get width.
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{
	int itt = BUFF_SIZE - 2;
	int is_negative = 0;
	long int EN = va_arg(var_types, long int);
	unsigned long int EM;

	EN = convert_size_number(EN, Z);

	if (EN == 0)
		buffer[itt--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	EM = (unsigned long int)EN;

	if (EN < 0)
	{
		EM = (unsigned long int)((-1) * EN);
		is_negative = 1;
	}

	while (EM > 0)
	{
		buffer[itt--] = (EM % 10) + '0';
		EM /= 10;
	}

	itt++;

	return (write_number(is_negative, itt, buffer, f, w, P, Z));
}

/**
 * print_binary - Prints an unsigned number
 * @var_types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f: Calculates active flags
 * @w: get width.
 * @P: Precision specification
 * @Z: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list var_types, char buffer[],
	int f, int w, int P, int Z)
{
	unsigned int EN, EM, itt, Add;
	unsigned int array[32];
	int count;

	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(P);
	UNUSED(Z);

	EN = va_arg(var_types, unsigned int);
	EM = 2147483648; /* (2 ^ 31) */
	array[0] = EN / EM;
	/*assuming 32 bits, itterate through*/
	for (itt = 1; itt < 32; itt++)
	{
		EM /= 2;
		array[itt] = (EN / EM) % 2;
	}
	for (itt = 0, Add = 0, count = 0; itt < 32; itt++)
	{
		Add += array[itt];
		if (Add || itt == 31)
		{
			char Z = '0' + array[itt];

			write(1, &Z, 1);
			count++;
		}
	}
	/* return the count of the binary. */
	return (count);
}

