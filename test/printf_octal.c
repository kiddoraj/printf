#include "main.h"
/**
 * printf_oct - prints an octal number.
 * @val: arguments
 *
 * Return: counter.
 */
int printf_oct(va_list val)
{
	int j;
	int *array;
	int counter = 0;
	unsigned int nbr = va_arg(val, unsigned int);
	unsigned int temp = nbr;

	while (nbr / 8 != 0)
	{
		nbr /= 8;
		counter++;
	}
	counter++;

	array = malloc(counter * sizeof(int));

	for (j = 0; j < counter; j++)
	{
		array[j] = temp % 8;
		temp /= 8;
	}
	for (j = counter - 1; j >= 0; j--)
	{
		_putchar(array[j] + '0');
	}
	free(array);
	return (counter);
}
