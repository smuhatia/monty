#include "monty.h"

/**
 * check_opcode - checks if the given token matches any opcode
 * @token: The token to check
 * @op_codes_funcs: the array of opcode structs
 * @working_stack: Double pointer to the top of the stack
 * @line_number: the line number where the opcode is found
 *
 * Return: 1 if a matching opcode is found, 0 if not
 */
int check_opcode(const char *token, instruction_t *op_codes_funcs,
stack_t **working_stack, unsigned int line_number)
{
	int i = 0;
	while (op_codes_funcs[i].opcode != NULL)
	{
		if (strcmp(token, op_codes_funcs[i].opcode) == 0)
		{
			if (strcmp(token, "push") == 0)
			{
				char *args = strtok(NULL, " \t\n");
				if (args == NULL)
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}

				check_integer(line_number, args);
				op_codes_funcs[i].f(working_stack, atoi(args));
			}
			else
			{
				op_codes_funcs[i].f(working_stack, line_number);
			}
			return 1;
		}
		i++;
	}
	return 0;
}

/**
 * process_file - process the instructions in the specified file
 * @filename: the name of the file to process
 *
 * Return: Nothing
 */
void process_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *token;

	stack_t *working_stack = NULL;

	instruction_t op_codes_funcs[] = {
		{"push", op_push}, {"pall", op_pall},
		{"print", op_pint}, {"pop", op_pop},
		{"swap", op_swap}, {"add", op_add},
		{"nop", op_nop}, {"sub", sub},
		{NULL, NULL}
	};
	if (file == NULL)
	{
		fprintf(stderr, "can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		token = strtok(line, "\t\n\r");
		if (token == NULL)
			continue;
		else if (token[0] == '#')
			continue;
		if (!check_opcode(token, op_codes_funcs, &working_stack, line_number))
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
	}
	cleanup(file, line, &working_stack);
}

/**
 * main - Entry point of the program
 *@argc: The number of command-line arguments
 * @argv: an array of command-line argument strings
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	process_file(argv[1]);

	return 0;
}
