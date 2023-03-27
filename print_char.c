#include "main.h"

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
void print_string(char *s)
{
	int n = 0;

	while (s[n] != '\0')
	{
		print_char(s[n]);
		n++;
	}
}
