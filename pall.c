#include "monty.h"
/**
 * pall - Function
 *
 * Description: Prints all the elements in the stack.
 *
 * @stack: Head of stack
 * @line_number: Line number (Not used in this case).
 *
 * Return: No return because it's a void function.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	node = *stack;
	if (node == NULL)
		return;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
