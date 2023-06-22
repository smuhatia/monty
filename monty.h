#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void handle_add(stack_t **stack, unsigned int line_number);
void handle_nop(stack_t **stack, unsigned int line_number);
void handle_pop(stack_t **stack, unsigned int line_number);
void handle_pint(stack_t **stack, unsigned int line_number);
void handle_push(stack_t **stack, unsigned int line_number);
void handle_swap(stack_t **stack, unsigned int line_number);
void handle_pall(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint(stack_t **head, unsigned int n);
size_t print_stack_t(stack_t **h);
int check_integer(unsigned int line_number, char *args);
int check_opcode(const char *token,
instruction_t *op_codes_funcs,
stack_t **working_stack, unsigned int line_number);
void process_file(const char *filename);
void cleanup(FILE *file, char *line, stack_t **stack);
void sub(stack_t **stack, unsigned int line_number);

#endif
