#include "main.h"
/**
 *_printf - produces output according to format
 *@format:character string
 *
 *Return:number of characters printed
 */
int _printf(const char *format, ...)
{
	convrt m[] = 
	{
		{"%c", printf_char},
		{"%s", printf_string},
		{"%%", printf_37},
		{"%d", printf_dec_int},
		{"%i". printf_int},
		{"%b", printf_binary},
		{"%r", printf_reversed},
		{"%R", printf_rot13},
		{"%u", printf_unsigned_integer},
		{"%o", printf_octal},
		{"%x", printf_hex},
		{"%X", printf_HEX},
		{"%S", printf_exclusive_string},
		{"%p", printf_pointer}
	};

	va_list args;

	int i = 0, j, len = 0;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
Here:

	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i += 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
