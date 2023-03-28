#include "main.h"
/**
 *print_num - prints a number
 *@foo: number input
 *
 *Return: Nothing
 */
void print_num(int foo)
{
	if (foo / 10 != 0)
	{
		print_num(foo / 10);
	}
	print_char((foo % 10) + '0');
}

/**
 *print_char - prints a character
 *@c: character input
 *
 *Return: write to stdout
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 *print_string - prints a string
 *@s: string input
 *
 *Return: Void
 */
int print_string(char *s)
{
	int n = 0;

	while (s[n] != '\0')
	{
		print_char(s[n]);
		n++;
	}
	return (n);
}
