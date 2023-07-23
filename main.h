#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


/**************ALL DEF**************/
#define HEXA_PREFIX "\\x"
#define HEXADECIMAL_FG (1 << 0)
#define HASH_FLAG (1 << 0)
#define BUFFER_Z 1024
#define NO_FLAGS 1
#define ADD_FLAGS 2
#define ZERO_FLAGS 4
#define HASH_FLAGS 8
#define SPACE 16
#define UNUSED(x) (void)(x)
#define LONG_STRING 2
#define SHORT_STRING 1

/**
 * struct format - Struct operator
 *
 * @fmt: The format.
 * @function_pointer: The function associated.
*/
struct format
{
	char format;
	int (*function_pointer)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format format_Type - Struct operator
 *
 * @fmt: The format.
 * @function_pointer: The function associated.
 */
typedef struct format format_Type;

int _printf(const char *format, ...);
int print(const char *format, int *count, va_list list,
		char buffer[], int all_flags, int width, int P, int size);
void print_buffer(char buffer[], int *buff_ind);
/***********types functions*************/
int write_characters(va_list var_types, char buffer[],
		int all_flags, int widths, int P, int char_size);
int strings(va_list var_types, char buffer[], int all_flags,
		int width, int P, int size);
int print_percent_sign(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size);
int print_integer(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size);
int Binary(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size);

/***************special print functions************/
int Upper_hexa_only(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size);
int hexa(va_list var_types, const char *hex_chars,
		char buffer[], int all_flags, char specifier,
		int width, int P, int size);
int print_hex_int(va_list var_types, char buffer[], int all_flags,
		int width, int P, int size);
int octal(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size);
int unsigned_int(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size);

/*************special functions 2*****************/
int Rot13string(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size);
int Reverse(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size);
int not_Printable(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size);
int Pointers(va_list var_types, char buffer[],
		int all_flags, int width, int P, int size);

/********aiding functions***********/
int printable(char ch);
int hexa_append(char ch, char buffer[], int index);
int numerals(char c);
long int size_conversion(long int number, int size);
unsigned long int convert_un_size(unsigned long int number, int size);

/**********Conditional functions**************/
int get_size(const char *format, int *count);
int get_width(const char *format, int *count, va_list list);
int handle_print(const char *format, int *count,
		va_list list, char buffer[],
		int all_flags, int width, int P, int size);
int get_flags(const char *format, int *count);
int get_precision(const char *format, int *count, va_list list);

/***********write functions****************/
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int all_flags, int width,
		int P, int length, char padding, char extra_c);
int unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd,
		char extra_c, int padd_start);
int write_char(char c, char buffer[], int flags,
		int width, int precision, int size);
#endif
