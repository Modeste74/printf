#include "main.h"

/**
  * print_char - Prints a char
  * @args: A list of variadic arguments
  *
  * Return: The length of the character
  */
int print_char(va_list args)
{
	_print_char(va_arg(args, int));
	return (1);
}

/**
  * print_string - Prints a string
  * @args: A list of variadic arguments
  *
  * Return: The length of the string
  */
int print_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_print_char(arg[i]);
			i++;
		}

		return (i);
	}

	_print_char('(');
	_print_char('n');
	_print_char('u');
	_print_char('l');
	_print_char('l');
	_print_char(')');
	return (6);
}

/**
  * print_integer - Prints a integer
  * @args: A list of variadic arguments
  *
  * Return: The length of the string
  */
int print_integer(va_list args)
{
	int count = 1, m = 0;
	unsigned int n = 0;

	n = va_arg(args, int);
	m = n;
	if (m < 0)
	{
		_print_char('-');
		m = m * -1;
		n = m;
		count += 1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}

	_integer(m);
	return (count);
}

/**
  * _integer - Prints a integer
  * @a: integer to print
  *
  * Return: Nothing
  */
void _integer(int a)
{
	unsigned int t;

	t = a;
	if (t / 10)
		_integer(t / 10);
	_print_char(t % 10 + '0');
}
