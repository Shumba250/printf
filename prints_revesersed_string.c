#include "main.h"

/**
 * print_reverse - writes the str in reverse
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_reverse(va_list arguments, char *buf, unsigned int ibuf)
{
char *str;
unsigned int z;
int a = 0;
char nill[] = "(llun)";

str = va_arg(arguments, char *);
if (str == NULL)
{
for (z = 0; nill[z]; z++)
ibuf = handl_buf(buf, nill[z], ibuf);
return (6);
}
for (z = 0; str[z]; z++)
;
a = z - 1;
for (; a >= 0; a--)
{
ibuf = handl_buf(buf, str[a], ibuf);
}
return (z);
}
