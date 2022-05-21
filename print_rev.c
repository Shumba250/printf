#include "main.h"

/**
 * print_rev - writes the str in reverse
 * @arguments: input the string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_rev(va_list arguments, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int a;
	int b = 0;
	char nill[] = "(llun)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (a = 0; nill[a]; a++)
			ibuf = handl_buf(buf, nill[a], ibuf);
		return (6);
	}
	for (a = 0; str[a]; a++)
		;
	b = a - 1;
	for (; b >= 0; b--)
	{
		ibuf = handl_buf(buf, str[b], ibuf);
	}
	return (a);
}
