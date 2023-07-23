#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	format_Type format_types[] = {
		{'c', write_characters}, {'s', strings}, {'%', print_percent_sign},
		{'i', print_integer}, {'d', print_integer}, {'b', Binary},
		{'u', unsigned_int}, {'o', octal}, {'x', print_hex_int},
		{'X', Upper_hexa_only}, {'p', Pointers}, {'S', not_Printable},
		{'r', Reverse}, {'R', Rot13string}, {'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*ind] == format_types[i].format)
			return (format_types[i].function_pointer(list, buffer, flags, width, precision, size));

	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &format[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
