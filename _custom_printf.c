#include "main.h"

void print_buffer(char buffer[], int *buffer_indicator);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int count, printed = 0, output = 0;
	int f, w, P, Z, buffer_indicator = 0;
	va_list arguments;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arguments, format);

	for (count = 0; format && format[count] != '\0'; count++)
	{
		if (format[count] != '%')
		{
			buffer[buffer_indicator++] = format[count];
			if (buffer_indicator == BUFF_SIZE)
				print_buffer(buffer, &buffer_indicator);
			/* write(1, &format[count], 1); */
			output++;
		}
		else
		{
			print_buffer(buffer, &buffer_indicator);
			f = get_flags(format, &count);
			w = get_width(format, &count, arguments);
			P = get_precision(format, &count, arguments);
			Z = get_size(format, &count);
			++count;
			printed = handle_print(format, &count, arguments, buffer,
				f, w, P, Z);
			if (printed == -1)
				return (-1);
			output += printed;
		}
	}

	print_buffer(buffer, &buffer_indicator);

	va_end(arguments);

	return (output);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buffer_indicator: represents the length.
 */
void print_buffer(char buffer[], int *buffer_indicator)
{
	if (*buffer_indicator > 0)
		write(1, &buffer[0], *buffer_indicator);

	*buffer_indicator = 0;
}
