#include "monty.h"
/**
 * pop - Function
 *
 * Description: Removes the top element of the stack.
 *
 * @stack: Pointer to the head of stack.
 * @line_number: Line number in the file.
 *
 * Return: No return because it's a void function.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(info.line);
		fclose(info.fp);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(node);
}
