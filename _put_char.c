#include "main.h"

/**
 * _put_char - prints a character
 * @c: the character
 *
 * Return: 1 on success
 * On error, -1 is returned, and errno is set appropriately.
 */

int _put_char(char c)
{
	return (write(1, &c, 1));
}
