#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @function_pointer: The function associated.
 */
struct fmt
{
	char fmt;
	int (*function_pointer)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @function_pointer: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *current_itt,
		va_list arguments, char buffer[], int f, int w, int P, int Z);
int print_char(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int print_string(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int print_percent(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int print_int(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int print_binary(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int print_unsigned(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int print_octal(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int print_hexadecimal(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int print_hexa_upper(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int print_hexa(va_list var_types, char point_to[],
		char buffer[], int f, char flag_ch, int w, int P, int Z);
int print_non_printable(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int print_pointer(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int get_flags(const char *format, int *itt);
int get_width(const char *format, int *itt, va_list arguments);
int get_precision(const char *format, int *itt, va_list arguments);
int get_size(const char *format, int *itt);
int print_reverse(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int print_rot13string(va_list var_types, char buffer[],
		int f, int w, int P, int Z);
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int ind, char buffer[],
		int flags, int width, int prec,
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size);
int is_printable(char c);
int append_hexa_code(char code, char buffer[], int i);
int is_digit(char c);
long int convert_size_number(long int N, int Z);
long int convert_size_unsgnd(unsigned long int N, int Z);

#endif /* MAIN_H */

