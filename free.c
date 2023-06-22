#include "monty.h"

/**
 * cleanup - free
 * @file: file object
 * @line: string for each line
 * @stack: doubly linked list stack
 * Return: nothing
 */
void cleanup(FILE *file, char *line, stack_t **stack)
{
	stack_t *current, *next;

	free(line);
	fclose(file);
	/* free the stack */

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
