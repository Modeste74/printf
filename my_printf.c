#include "main.h"

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
			stdout, print_char(va_arg(args, int));
			i++;
			break;
		case  's':
			stdout, print_string(va_arg(args, char *));
			i++;
			break;
		case  '%':
			stdout, print_char('%');
			i++;
			break;
		default:
			i++;
			continue;
		}
		}
		else
			stdout, print_char(format[i]);
		i++;

	}
	va_end(args);
	return (i);
}
