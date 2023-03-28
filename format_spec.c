#include "main.h"

/**
  * print_format - Prints a format
  * @format: The format to prints
  * @args: A list of variadic arguments
  * Return: The length of the format
  */
int print_format(const char *format, va_list args)
{
	int count = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			i++;
			while (format[i] == ' ')
				i++;
			if (format[i] == '%')
				count += _print_char(format[i]);
			if (format_checker(format[i]) == 0)
			{
				count = print_invalid(format[i - 1], format[i], count);
			}
			else
			{
				count += print_spec(format[i], args);
			}
		}
		else
		{
			count += _print_char(format[i]);
		}
		i++;
	}
	return (count);
}

/**
  * print_spec - Prints a valid specifier
  * @format: The specifier to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the specifier
  */
int print_spec(char format, va_list args)
{
	int i  = 0, length = 0;
	fmt_t _types[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{NULL, NULL}
	};

	while (_types[i].type)
	{
		if (*_types[i].type == format)
			length = _types[i].f(args);

		i++;
	}

	return (length);
}

/**
  * print_invalid - Prints a invalid specifier
  * @prev_format: The previous specifier of actual specifier
  * @format: The specifier to prints
  * @count: The current count before prints invalid specifiers
  *
  * Return: The current count after prints invalid specifiers
  */
int print_invalid(char prev_format, char format, int count)
{
	count += _print_char('%');

	if (prev_format == ' ')
	{
		count += _print_char(' ');
		count += _print_char(format);
	}
	else
	{
		count += _print_char(format);
	}

	return (count);
}

/**
  * format_checker - validate the type
  * @_type: character to be comparate
  *
  * Return: 1 if char is equal to a type
  */
int format_checker(char _type)
{
	char _types[] = {'c', 's', 'd', 'i', 'b', '%'};
	int i = 0;

	while (_types[i])
	{
		if (_types[i] == _type)
			return (1);
		i++;
	}
	return (0);
}
