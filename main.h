#ifndef  _main_h
#define _mian_h
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
  * struct specifiers - Struct specifiers
  * @specifier: The conversion specifier
  * @f: The function pointer
  */
typedef struct form
{
	char *type;
	int (*f)(va_list args);
} fmt_t;

int _print_char(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_format(const char *format, va_list args);
int print_spec(char format, va_list args);
int print_invalid(char prev_format, char format, int count);
int print_integer(va_list args);
void _integer(int a);
int print_binary(va_list args);
void _int_binary(int a);
int format_checker(char _type);

#endif
