#include "monty.h"
/**
 * swap - Function
 *
 * Description: Swaps the two top elements of the stack.
 *
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 *
 * Return: No return because it's a void function.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(info.fp);
		free(info.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	node->next = (*stack)->next;
	(*stack)->next = node;
	node->prev = *stack;
}
