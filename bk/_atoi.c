#include "monty.h"

/**
 * _atoi - convert a string to an integer.
 * @s: char type string
 * @n: pointer to the coverted int
 * Return: integer converted
 */

int _atoi(char *s, int *n)
{
	int sign = 1, resp = 0, first_num, i;

	for (first_num = 0; !(s[first_num] >= 48 && s[first_num] <= 57); first_num++)
	{
		if (s[first_num] == '-')
		{
			sign *= -1;
		}
	}
	for (i = first_num; s[i] ; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			resp *= 10;
			resp += (s[i] - 48);
		}
		else
			return (-1);
	}

	*n = resp * sign;
	(void)(n);
	return (0);
}
