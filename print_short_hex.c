#include "main.h"
/**
 * prinhhex - prints a short decimal in hexadecimal
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinhhex(va_list arguments, char *buf, unsigned int ibuf)
{
	short int input, i, negative, c, x;
	char *hexadecimal, *binary;

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

	binary = malloc(sizeof(char) * (16 + 1));
	binary = fill_binary_array(binary, input, negative, 16);
	hexadecimal = malloc(sizeof(char) * (4 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 4);
	for (x = i = c = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && x == 0)
			x = 1;
		if (x)
		{
			ibuf = handl_buf(buf, hexadecimal[i], ibuf);
			c++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (c);
}
