#include "monty.h"
/**
 * push - Function
 *
 * Description: Push a node to a stack.
 *
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the command in the monty file.
 *
 * Return: No return because it's a void function
 */
void push(stack_t **stack, unsigned int line_number)
{
	FILE *fp;
	char line[100];
	stack_t *new;
	unsigned int line_num = 1;
	char **op_arr;

	memset(line, '\0', 100);
	fp = fopen(filename, "r");
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		if (line_number == line_num)
			op_arr = extractTokens(line);
		line_num++;
	}
	if (is_int(op_arr[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all_strings(op_arr);
		free_stack(*stack);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all_strings(op_arr);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(op_arr[1]);
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
	free_all_strings(op_arr);
}
