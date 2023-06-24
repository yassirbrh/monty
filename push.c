#include "monty.h"
/**
 * push -  Function
 *
 * @stack: Head of stack.
 * @line_number: Line counter.
 *
 * Return: No return because it's a void function.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i, j = 0, n, flag = 0;

	if (info.arg)
	{
		if (info.arg[0] == '-')
			j++;
		for (i = j; info.arg[i] != '\0'; i++)
		{
			if (info.arg[i] > 57 || info.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(info.fp);
			free(info.line);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(info.fp);
		free(info.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(info.arg);
	if (info.flag == 0)
		addnode(stack, n);
	else
		addqueue(stack, n);
}
