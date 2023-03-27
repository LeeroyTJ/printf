#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert convert_t;

int _put_char(char c);
int _printf(const char *format, ...);
int _printchar(va_list);
int _printpercent(va_list);
int _printstr(va_list);
int execute(const char *format, convert_t format_list[], va_list ap);

#endif
