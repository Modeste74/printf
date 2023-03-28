#include "main.h"

/**
 *_printf - produces output according to format
 *@format: pointer to input
 *
 *Return: Zero
 */
int _printf(const char *format, ...)
{
	int i;
	va_list args;

	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '\0' && format[i] != '%')
		{
			print_char(format[i]);
		}
		if (format[i] == '%' && format[i + 1] != '%')
		{
			format_check(format[i + 1], args);
			i++;
		}
		if (format[i] == '%' && format[i + 1] == '%')
		{
			print_char('%');
			i++;
		}
		if (format[i + 1] == '\0')
		{
			return (-1);
		}
	}
	va_end(args);
	return (i);
}
