#include "monty.h"
/**
 * free_stack - Function
 *
 * Description: Frees a linked list.
 *
 * @stack: Head of the stack.
 *
 * Return: No return because it's a void function.
 */
void free_stack(stack_t *stack)
{
	stack_t *node;

	node = stack;
	while (stack != NULL)
	{
		stack = stack->next;
		free(node);
		node = stack;
	}
}
