#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - function that prints an unsigned number
 * @types: arguments list
 * @buffer: array to handle print
 * @flags: Calculates active flags
 * @width: width
 * @precision: specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */

int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[j--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}
	j++;
	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal -function that prints an unsigned number in octal
 * @types: arguments list
 * @buffer: array to handle print
 * @flags: Calculates active flags
 * @width: width
 * @precision: specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[j--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[j--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[j--] = '0';
	j++;
	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - function that prints an unsigned number in hexadecimal
 * @types: arguments list
 * @buffer: array to handle print
 * @flags: Calculates active flags
 * @width: width
 * @precision: specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - function that prints an unsigned number in upper hexadecimal in upper case
 * @types: arguments list
 * @buffer: array to handle print
 * @flags: Calculates active flags
 * @width: width
 * @precision: specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - function that prints a hexadecimal number in lower or upper
 * @types: arguments list
 * @map_to: Array of values to map the number
 * @buffer: array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: width
 * @precision: specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[j--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[j--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}
	j++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
