#include "main.h"
void print_num(int foo);
/**
 *_printf - produces output according to format
 *@format: pointer to input
 *
 *Return: Zero
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;

	if (format == NULL)
	{
		return (0);
	}
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
		switch (format[i + 1])
		{
		case  'c':
			print_char(va_arg(args, int));
			i++;
			break;
		case  's':
			print_string(va_arg(args, char *));
			i++;
			break;
		case  '%':
			print_char('%');
			i++;
			break;
		case  'd':
			print_num(va_arg(args, int));
			i++;
			break;
		case  'i':
			print_num(va_arg(args, int));
			i++;
			break;
		default:
			i++;
			continue;
		}
		}
		else
			print_char(format[i]);
		i++;

	}
	va_end(args);
	return (i);
}
