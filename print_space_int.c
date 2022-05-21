#include "main.h"
/**
 * prinsint - prints int begining with space
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinsint(va_list arguments, char *buf, unsigned int ibuf)
{
	int input;
	unsigned int int_in, int_temp, i, div;

	input = va_arg(arguments, int);
	if (input < 0)
	{
		int_in = input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
	}
	else
	{
		int_in = input;
		ibuf = handl_buf(buf, ' ', ibuf);
	}
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + 1);
}
