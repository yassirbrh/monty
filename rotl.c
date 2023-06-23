#include "monty.h"
/**
 * rotl - Function
 *
 * Description: Rotates the stack to the top.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 *
 * Return: No return because it's a void function.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack, *current;

	(void)line_number;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	node->next = NULL;
	node->prev = current;
}
