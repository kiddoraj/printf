#include "main.h"
/**
 * printf_int - prints integer
 * @args: argument
 *
 * Return: number of characters printed
 */
int printf_int(va_list args)
{
	int n = va_arg(args, int);
	int nbr, last = n % 10, dgt, zed = 1;
	int  j = 1;

	n = n / 10;
	nbr = n;

	if (last < 0)
	{
		_putchar('-');
		nbr = -nbr;
		n = -n;
		last = -last;
		j++;
	}
	if (nbr > 0)
	{
		while (nbr / 10 != 0)
		{
			zed *=  10;
			nbr = nbr / 10;
		}
		nbr = n;

		while (zed > 0)
		{
			dgt = nbr / zed;
			_putchar(digit + '0');
			nbr = nbr - (dgt * zed);
			zed = zed / 10;
			j++;
		}
	}
	_putchar(last + '0');

	return (j);
}

/**
 * printf_dec - prints decimal int
 * @args: argument 
 *
 * Return: number of characters printed
 */

int printf_dec(va_list args)
{
	int n = va_arg(args, int);
	int nbr, last = n % 10, dgt;
	int  j = 1;
	int zed = 1;
v
	n = n / 10;
	nbr = n;

	if (last < 0)
	{
		_putchar('-');
		nbr = -nbr;
		n = -n;
		last = -last;
		j++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			zed = zed * 10;
			nbr = nbr / 10;
		}
		nbr = n;
		while (zed > 0)
		{
			dgt = nbr / zed;
			_putchar(dgt + '0');
			nbr = nbr - (dgt * zed);
			zed = zed / 10;
			j++;
		}
	}
	_putchar(last + '0');

	return (i);
}
