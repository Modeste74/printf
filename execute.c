#include "main.h"

/**
 *format_check - checks charcter and calls function
 *@format: character input
 *@args: argument passed
 *
 *Return: Nothing
 */
void format_check(const char format, va_list args)
{
	int i;

	fmt print_format[] = {{'c', print_char},
			      {'s', print_string},
			      {'d', print_num},
			      {'i', print_num},
			      {NULL, NULL}};
	for (i = 0; print_format[i] != '\0'; i++)
	{
		if (format == print_format[i].type)
		{
			print_format[i].funct(va_arg(args, int *));
			break;
		}
	}
}
