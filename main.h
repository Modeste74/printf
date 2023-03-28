#ifndef _main_
#define _main_
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
 *struct Form - structure for the format
 *@type: Format specifier
 *@funct: Function pointer
 *
 */
struct Form
{
	char type;
	void (*funct)(char, va_list);
};

typedef struct Form fmt;
int _printf(const char *format, ...);
int print_char(char c);
void print_string(char *s);
void print_num(int foo);
void format_check(const char format, va_list args);
void handler_ptr(char c, va_list list);
#endif
