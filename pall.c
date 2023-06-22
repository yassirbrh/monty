#include "monty.h"
/**
 * pall - Function
 *
 * Description: Prints all the elements in the stack.
 *
 * @stack: Pointer to the pointer to the stack.
 * @line_number: The number of line of the command in the monty file.
 *
 * Return: No return because it's a void function.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void) line_number;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
