#include "main.h"
/**
 *_printf - produces output according to a format
 *@format:character string
 *
 *Return:the number of characters printed 
 */
int _printf(const char *format, ...)
{
	int print_chr;

	conver_t f_list[] = 
	{
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_interger},
		{"i", print_interger},
		{NULL, NULL}
	};

	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	print_chr = parser(format, f_list, arg_list);

	va_end(arg_list);
	return (print_chr);
}
