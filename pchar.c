#include "monty.h"
/**
 * pchar - Function
 *
 * Description: Prints the char at the top of the stack.
 *
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number.
 *
 * Return: No return because it's a void function.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		fclose(info.fp);
		free_stack(*stack);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 ||  (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		fclose(info.fp);
		free_stack(*stack);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
