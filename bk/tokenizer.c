#include "monty.h"
/**
 *split_line - parse file into a list of arguments
 *@line - pointer to the line to be tokenized
 *Return: returns a pointer to the first token found in the string
 */

#define _TOK_DELIM " \t\r\n\a"
char **split_line(char *line)
{
	/*int bufsize = _TOK_BUFSIZE;*/
	int position = 0;
	char **tokens = NULL;
	char **tmp = NULL;
	char *token;

	token = strtok(line, _TOK_DELIM);

	while (token != NULL)
	{
		tmp = realloc(tokens, sizeof(char *) * (position + 2));
		if (tmp == NULL)
		{
			fprintf(stderr, "sh: allocation error\n");
			exit(EXIT_FAILURE);
		}
		tokens = tmp;
		tokens[position] = token;
		token = strtok(NULL, _TOK_DELIM);
		position++;
	}
	tokens[position] = NULL;
	return (tokens);
}
