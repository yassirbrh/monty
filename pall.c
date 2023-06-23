#include "monty.h"
/**
 * pall - Function
 *
 * Description: Prints all the elements in the stack.
 *
 * @head: Head of stack
 * @count: Line number (Not used in this case).
 *
 * Return: No return because it's a void function.
 */
void pall(stack_t **head, unsigned int count)
{
	stack_t *node;
	(void)count;

	node = *head;
	if (node == NULL)
		return;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
