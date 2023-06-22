#include "monty.h"

/**
 * check_integer- checks if the given string is a valid integer
 * @line_number: The line number where the integer is being checked
 * @args: the string to be checked
 *
 * Return: 1 if the string is a valid integer, otherwise exits the program
 */
int check_integer(unsigned int line_number, char *args)
{
	if (args == NULL || *args == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* skip the optional sign character */
	if (*args == '-' || *args == '+')
		args++;

	/* check if the remaining characters are digits */
	while (*args != '\0')
	{
		if (!isdigit(*args))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		args++;
	}
	return 1;
}
