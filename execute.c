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

	fmt print_format[] = {{'c', handler_ptr},
			      {'s', handler_ptr},
			      {'d', handler_ptr},
			      {'i', handler_ptr},
			      {'\0', '\0'}};
	for (i = 0; print_format[i].type != '\0'; i++)
	{
		if (format == print_format[i].type)
		{
			print_format[i].funct(format, args);
			break;
		}
	}
}
