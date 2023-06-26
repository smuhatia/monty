#include "monty.h"

/**
 * op_pall - prints all elements in stack
 * @stack: double pointer to top of stack
 * @line_no: line number where pall op is performed
 * Return: NULL
 */

void op_pall(stack_t **stack, unsigned int line_no)
{
	stack_t *current = *stack;

	(void)line_no;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * op_push - pushes an element to the stack
 * @stack: double pointer to the top stack
 * @line_no: line number whre push op is performed
 * Return: NULL
 */

void op_push(stack_t **stack, unsigned int line_no)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = line_no;
	newnode->prev = NULL;
	newnode->next = NULL;

	if (*stack != NULL)
		(*stack)->prev = newnode;
	newnode->next = *stack;
	*stack = newnode;
}

/**
 * op_swap - swaps top two elements in stack
 * @stack: double pointer to the top of stack
 * @line_no: line number where swap op is performed
 * Return: NULL
 */

void op_swap(stack_t **stack, unsigned int line_no)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = (*stack)->next;

	top->prev = next;
	top->next = next->next;

	next->prev = NULL;
	next->next = top;

	if (top->next != NULL)
		top->next->prev = top;

	*stack = next;
}
