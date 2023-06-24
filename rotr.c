#include "monty.h"
/**
 * rotr - Function
 *
 * Description: Rotates the stack to the bottom.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 *
 * Return: No return because it's a void function.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;
	while (*stack != NULL)
	{
		node = *stack;
		*stack = (*stack)->next;
		node->next = node->prev;
		node->prev = *stack;
	}
	if (*stack == NULL)
		*stack = node;
}
