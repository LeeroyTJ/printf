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
		{"u", _print_unsigned_int},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{"p", _print_addr},
		{"b", print_binary},
		{"r", print_rev},
		{"R", rot13}
	};

	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	printed_char = execute(format, format_list, ap);

	va_end(ap);
	return (printed_char);
}
