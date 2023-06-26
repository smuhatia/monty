#include "monty.h"

/**
 * op_add - adds top two elements in the stack
 * @stack: double pointer to the top of stack
 * @line_number: the line num where the add op is performed
 * Return: Null
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = (*stack)->next;

	next->n += top->n;

	*stack = next;
	(*stack)->prev = NULL;
	free(top);
}

/**
 * op_pop - removes top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number where pop operation is perfomed
 * Return: NULL
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}

/**
 * op_pint - prints value at the top of stack
 * @stack: double pointer to the top of stack
 * @line_number: line number where the pint operation is performed
 * Return: NULL
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * op_nop - performs nothing
 * @stack: double pointer to the top of the stack
 * @line_number: line number where nop operation is performed
 * Return: NULL
 */

void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - prints value at the top of stack
 * @stack: double pointer to the top of stack
 * @line_number: line number whre pint operation happens
 * Return: NULL
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int sub_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short \n", line_number);
		exit(EXIT_FAILURE);
	}

	sub_result = (*stack)->next->n - (*stack)->n;
	op_pop(stack, line_number);
	(*stack)->n = sub_result;
}
