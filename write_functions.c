#include "main.h"


/***************** WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFFER_Z - ind - 1;
	char padding = ' ', other_ch = 0;

	UNUSED(size);
	if ((flags & ZERO_FLAGS) && !(flags & NO_FLAGS))
		padding = '0';
	if (is_negative)
		other_ch = '-';
	else if (flags & ADD_FLAGS)
		other_ch = '+';
	else if (flags & SPACE)
		other_ch = ' ';
	return (write_num(ind, buffer, flags, width, precision,
				length, padding, other_ch));
}
/**
 * write_num - Writes a num using a buffer with padding and extra characters
 * @ind: Index at which the number starts in the buffer
 * @buffer: Buffer containing the number to be printed
 * @flags: Flags used for formatting (e.g., No_FLAGS).
 * @width: Width specifier for formatting.
 * @prec: Precision specifier for formatting.
 * @length: Number length.
 * @padd: Padding character used for formatting
 * @extra_c: Extra character to be added to the output.
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[], int flags,
		int width, int prec, int length, char padd, char extra_c)
{
	if (prec == 0 && ind == BUFFER_Z - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFFER_Z - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	while (prec > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		int i;
		int padd_start = (padd == '0') ? 1 : 0;

		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (padd == '0')
			buffer[--padd_start] = extra_c;
		else
			buffer[--ind] = extra_c;
		if (flags & NO_FLAGS)
			/* Assign extra char to the left of buffer */
			return (write(1, &buffer[ind], length) + write(1,
			    &buffer[1], i - 1));
		else
			/* Assign extra char to the left of buffer or padd */
			return (write(1, &buffer[padd_start], i - padd_start)
			    + write(1, &buffer[ind],
				    length - (1 - padd_start)));
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * unsgnd - Writes an unsigned number with specified width and precision.
 *
 * @is_negative: Flag indicating if the number is negative (not used in this function).
 * ind: Index at which the number starts in the buffer.
 * flags: Flags used for formatting (e.g., ZERO_FLAGS, NO_FLAGS).
 * width: Width specifier for formatting.
 * precision: Precision specifier for formatting
 * size: Size specifier (not used in this function).
 * @number: Unsigned number to be printed.
 * buffer: Buffer containing starts in the buffer.
 *
 * Return: Number of written characters.
 */

int unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size) {
    /* The number is stored at the buffer's right and starts at position i */
	int length = BUFFER_Z - ind - 1;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);
	if (precision == 0 && ind == BUFFER_Z - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */
	if (precision > 0 && precision < length)
		padd = ' ';
	for (; precision > length; --ind, ++length)
		buffer[ind - 1] = '0';
	if ((flags & ZERO_FLAGS) && !(flags & NO_FLAGS))
		padd = '0';
	if (width > length)
	{
		int i;

		i = 0;
		while (i < width - length)
			buffer[i++] = padd;
		buffer[i] = '\0';
		if (flags & NO_FLAGS)
		/* Assign extra char to the left of the buffer [buffer > padd] */
		return (write(1, &buffer[ind],
					length) + write(1, &buffer[0], i));
	else /* Assign extra char to the left of padding [padd > buffer] */
		return (write(1, &buffer[0], i) +
				write(1, &buffer[ind], length));
	}
	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address with specified width and precision
 * @pointer: Pointer to be printed
 * @all_flags: Flags specifier
 * @width: Width specifier
 * @P: Precision specifier
 *
 * Return: Number of written chars.
 */
#include <unistd.h>

#define BUFF_SIZE 100
#define F_MINUS 2

int write_pointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (!padd_start)
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			if (flags & F_MINUS)
				/* Assign extra char to the left of buffer */
				return (write(1, &buffer[ind],
							length) + write(1, &buffer[3], i - 3));
			else /* Assign extra char to the left of buffer */
				return (write(1, &buffer[3],
							i - 3) + write(1, &buffer[ind], length));
		}
		else /* Assign extra char to the left of padding */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start],
						i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

/**
 * write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */


int write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = (flags & ZERO_FLAGS) ? '0' : ' ';

	UNUSED(precision);
	UNUSED(size);
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1],
						width - 1) + write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
