#include "main.h"
/**
 * fill_short_oct_array - calculates a short octal number
 *
 * @bnr: array where is stored the binary.
 * @oct: array where is stored the octal.
 *
 * Return: binary array.
 */
char *fill_short_oct_array(char *bnr, char *oct)
{
	int a, i, b, octal, limits;

	oct[6] = '\0';
	for (i = 15, octal = 5; i >= 0; i--, octal--)
	{
		if (i > 0)
			limits = 4;
		else
			limits = 1;
		for (a = 0, b = 1; b <= limits; b *= 2, i--)
			a = ((bnr[i] - '0') * b) + a;
		i++;
		oct[octal] = a + '0';
	}
	return (oct);
}
