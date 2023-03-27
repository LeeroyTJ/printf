#include "main.h"

/**
 * execute - prints a formatted string
 * @format: A string containing all the desired characters
 * @format_list: A list of all the posible functions
 * @ap: list of arguments
 * Return: characters printed
 */
int execute(const char *format, convert_t format_list[], va_list ap)
{
	int i, j, r_value, printed_char;

	printed_char = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; format_list->sym != NULL; j++)
			{
				if (format[i + 1] == format_list[j].sym[0])
				{
					r_value = format_list[j].f(ap);
					if (r_value == -1)
						return (-1);

					printed_char += r_value;
					break;
				}
			}
			if (format_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_put_char(format[i]);
					_put_char(format[i + 1]);
					printed_char = printed_char + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_put_char(format[i]);
			printed_char++;
		}
	}
	return (printed_char);
}
