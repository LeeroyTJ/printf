#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: a character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed_char;
	convert_t format_list[] = {
		{"c", _printchar},
		{"s", _printstr},
		{"%", _printpercent},
		{"d", _print_int},
		{"i", _print_int},
		{"b", print_binary}
	};

	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	printed_char = execute(format, format_list, ap);

	va_end(ap);
	return (printed_char);
}
