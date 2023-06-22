#include "monty.h"
#include <string.h>
#define MAX_TOKENS 100
/**
 * extractTokens - Function
 *
 * Description: Returns an array of strings that are separated by space or tab.
 *
 * @input: Pointer to the string input.
 *
 * Return: An array of strings.
 */
char **extractTokens(char *input)
{
	char **tokens = malloc(MAX_TOKENS * sizeof(char *));
	char *token;
	int numTokens = 0;

	token = strtok(input, " \t\n");
	while (token != NULL)
	{
		tokens[numTokens] = strdup(token);
		numTokens++;
		token = strtok(NULL, " \t\n");
	}
	tokens[numTokens] = NULL;
	return (tokens);
}
/**
 * strdup - Function
 *
 * Description: Creates a copy of a string.
 *
 * @str: Pointer to the string to copy.
 *
 * Return: Pointer to the new string.
 */
char *strdup(const char *str)
{
	size_t len = strlen(str);
	char *new_str;

	if (str == NULL)
		return (NULL);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	strcpy(new_str, str);
	return (new_str);
}
/**
 * is_int - Function
 *
 * Description: Checks if a string is an integer after conversion.
 *
 * @str: Pointer to the string to check.
 *
 * Return: 1 if it is an integer.
 *         0 if it is not.
 */
int is_int(char *str)
{
	size_t i = 0;

	if (str == NULL)
		return (0);
	for (i = 0; i < strlen(str); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
