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
	stack_t *node = *stack;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (node->next != NULL)
			node = node->next;
		node->prev->next = node->next;
		node->prev = NULL;
		node->next = *stack;
		(*stack)->prev = node;
		*stack = node;
	}
}
