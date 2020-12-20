#include "../monty.h"

/**
 * isint - checks if everything inside a string is a number
 * @intstring: a string expected to contain all int chars
 * Return: returns 1 if everything is int 0 if not
 */
int isint(char *intstring)
{
	while (*intstring)
	{
		if (*intstring > '9' || *intstring < '0')
			return (0);
		intstring += 1;
	}
	return (1);
}

