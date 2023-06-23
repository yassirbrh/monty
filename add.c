#include "monty.h"
/**
 * add - Function
 *
 * Description: Adds the top two elements of the stack.
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 *
 * Return: No return because it's a void function.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		fclose(info.fp);
		free_stack(*stack);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
