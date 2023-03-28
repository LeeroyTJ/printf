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
int _print_int(va_list);
int _print_unsigned_int(va_list);
<<<<<<< HEAD
int _print_unsigned_int(va_list);
=======
int print_binary(va_list);
char *rev_string(char *s);
void write_base(char *s);
unsigned int base_len(unsigned int num, int base);
char *_memcpy(char *dest, char *src, unsigned int n);
>>>>>>> c9bd74449c179bf4c9473bfb203c4f3f4922f7f1

#endif
