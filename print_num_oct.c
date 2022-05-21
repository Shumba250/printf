#include "main.h"
/**
 * prinnoct - print the number in octal begining with zero
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinnoct(va_list arguments, char *buf, unsigned int ibuf)
{
	int input, i, negative, c, x;
	char *octal, *binary;

	input = va_arg(arguments, int);
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
	ibuf = handl_buf(buf, '0', ibuf);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, input, negative, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = fill_oct_array(binary, octal);
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
	return (c + 1);
}
