#include "main.h"
/**
 * fill_oct_array - writes the character c to stdout
 *
 * @bnr: array where is stored the binary.
 * @oct: array where is stored the octal.
 *
 * Return: binary array.
 */
char *fill_oct_array(char *bnr, char *oct)
{
	int a, i, b, octal, limits;

	oct[11] = '\0';
	for (i = 31, octal = 10; i >= 0; i--, octal--)
	{
		if (i > 1)
			limits = 4;
		else
			limits = 2;
		for (a = 0, b = 1; b <= limits; b *= 2, i--)
			a = ((bnr[i] - '0') * b) + a;
		i++;
		oct[octal] = a + '0';
	}
	return (oct);
}
