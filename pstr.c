#include "monty.h"
/**
 * pstr - Function
 *
 * Description: Prints the string starting at the top of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 *
 * Return: No return because it's a void function.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;
	while (node != NULL)
	{
		if (node->n <= 0 || node->n > 127)
			break;
		printf("%c", node->n);
		node = node->next;
	}
	printf("\n");
}
