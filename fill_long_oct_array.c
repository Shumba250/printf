#include "main.h"
/**
 * fill_long_oct_array - calculates a long octal number
 *
 * @bnr: array where is stored the binary.
 * @oct: array where is stored the octal.
 *
 * Return: binary array.
 */
char *fill_long_oct_array(char *bnr, char *oct)
{
	int a, i, j, octal, limit;

	oct[22] = '\0';
	for (i = 63, octal = 21; i >= 0; i--, octal--)
	{
		if (i > 0)
			limit = 4;
		else
			limit = 1;
		for (a = 0, j = 1; j <= limit; j *= 2, i--)
			a = ((bnr[i] - '0') * j) + a;
		i++;
		oct[octal] = a + '0';
	}
	return (oct);
}
