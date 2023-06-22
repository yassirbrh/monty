#include "monty.h"
#define LINE_LEN 100
/**
 * interface - Function
 *
 * Description: The entry point to monty operations.
 *
 * Return: No return because it's a void function.
 */
void interface(void)
{
	char line[LINE_LEN];
	unsigned int line_num = 1, i = 0, op_found = 0;
	FILE *fp = fopen(filename, "r");
	char **opcode_str;
	stack_t *new_stack = NULL;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	memset(line, '\0', LINE_LEN);
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		opcode_str = extractTokens(line);
		op_found = 0;
		i = 0;
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(instructions[i].opcode, opcode_str[0]) == 0)
			{
				free_all_strings(opcode_str);
				op_found = 1;
				instructions[i].f(&new_stack, line_num);
				break;
			}
			i++;
		}
		if (op_found == 0)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode_str[0]);
			free_all_strings(opcode_str);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		line_num++;
	}
	free_stack(new_stack);
	fclose(fp);
}
