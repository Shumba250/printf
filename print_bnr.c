#include "main.h"

/**
 * print_bnr - prints decimal in binary
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_bnr(va_list arguments, char *buf, unsigned int ibuf)
{
	int input, c, i, x, negative;
	char *binary;

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
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, input, negative, 32);
	x = 0;
	for (c = i = 0; binary[i]; i++)
	{
		if (x == 0 && binary[i] == '1')
			x = 1;
		if (x == 1)
		{
			ibuf = handl_buf(buf, binary[i], ibuf);
			c++;
		}
	}
	free(binary);
	return (c);
}
