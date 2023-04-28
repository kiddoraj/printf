#include "main.h"
/**
 * printf_char - prints a char.
 * @val:args
 *
 * Return: 1.
 */
int printf_char(va_list val)
{
	char s;

	s = va_arg(val, int);

	_putchar(s);
	return (1);
}
