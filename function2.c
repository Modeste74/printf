#include "main.h"

/**
  * print_binary - Prints a int converted to binary
  * @args: A list of variadic arguments
  *
  * Return: The number of printed digits
  */
int print_binary(va_list args)
{
	unsigned int x = 0;
	int b = 0, new = 0;

	new = va_arg(args, int);
	x = new;
	if (new < 0)
	{
		_print_char('1');
		new = new * -1;
		x = new;
		b += 1;
	}
	while (x > 0)
	{
		x = x / 2;
		b++;
	}
	_int_binary(new);
	return (b);
}

/**
  * _int_binary - Prints a binary
  * @a: integer to print
  *
  */
void _int_binary(int a)
{
	unsigned int t;

	t = a;
	if (t / 2)
		_int_binary(t / 2);
	_print_char(t % 2 + '0');
}
