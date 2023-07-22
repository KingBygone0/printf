#include "main.h"

/**
 * _printf - Custom Printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int count, printed_chars = 0, print = 0;
	int f, w, p, s, buffer_indicator = 0;
	va_list arguments;
	char buffer[BUFFER_Z];

	if (format == NULL)
	return (-1);

	va_start(arguments, format);

	for (count = 0; format && format[count] != '\0'; count++)
	{
		if (format[count] != '%')
	{
		buffer[buffer_indicator++] = format[count];
		if (buffer_indicator == BUFFER_Z)
			print_buffer(buffer, &buffer_indicator);
		/* Increment chars */
	}
	else
	{
		print_buffer(buffer, &buffer_indicator);
		f = get_flags(format, &count);
		w = get_width(format, &count, arguments);
		p = get_precision(format, &count, arguments);
		s = get_size(format, &count);
		count++;
		printed_chars = handle_print(format, &count, arguments, buffer, f, w, p, s);
		if (printed_chars == -1)
		return (-1);
		print += printed_chars;
	}
	}

	print_buffer(buffer, &buffer_indicator);

	va_end(arguments);
	/* Return the number of characters printed */
	return (print);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters
 * @buff_ind: Index at which to add the next character,
 * represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
