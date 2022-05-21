#include "main.h"
/**
 * prinloct - prints long decimal number in octal
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int prinloct(va_list arguments, char *buf, unsigned int ibuf)
{
	long int input, i, negative, c, x;
	char *octal, *binary;

	input = va_arg(arguments, long int);
	negative = 0;
	if (input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		negative = 1;
	}

	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, input, negative, 64);
	octal = malloc(sizeof(char) * (22 + 1));
	octal = fill_long_oct_array(binary, octal);
	for (x = i = c = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && x == 0)
			x = 1;
		if (x)
		{
			ibuf = handl_buf(buf, octal[i], ibuf);
			c++;
		}
	}
	free(binary);
	free(octal);
	return (c);
}
