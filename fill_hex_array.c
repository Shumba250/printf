#include "main.h"
/**
 * fill_hex_array - writes the character c to stdout
 *
 * @bnr: array where is stored the binary.
 * @hex: array where is stored the hexadecimal.
 * @isupp: integer that determines if the hexadecimal array is
 * in uppercase or lowercase letter.
 * @limit: size of hex
 * Return: binary array.
 */
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit)
{
	int c, a, b, test;

	hex[limit] = '\0';
	if (isupp)
		test = 55;
	else
		test = 87;
	for (a = (limit * 4) - 1; a >= 0; a--)
	{
		for (c = 0, b = 1; b <= 8; b *= 2, a--)
			c = ((bnr[a] - '0') * b) + c;
		a++;
		if (c < 10)
			hex[a / 4] = c + 48;
		else
			hex[a / 4] = c + test;
	}
	return (hex);
}
