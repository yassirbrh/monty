#include "monty.h"

/**
 * exec_op - Function
 *
 * @stack: Head of linked list (Stack or Queue).
 * @count: Line count.
 * @fp: Pointer to monty file.
 * @line: Line content.
 *
 * Return: 0 if failed.
 *         1 if succeed.
 */
int exec_op(char *line, stack_t **stack, unsigned int count, FILE *fp)
{
	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(line, " \n\t");
	if (op && op[0] == '#')
		return (0);
	info.arg = strtok(NULL, " \n\t");
	while (ops[i].opcode && op)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(fp);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
