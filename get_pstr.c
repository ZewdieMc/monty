#include "monty.h"

/**
 * get_pstr - function that prints ascii value of elements
 * @stack: pointer to head of the stack
 * @line_number: where the instruction appears
 * Description: 12. pstr
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void get_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;

	(void)line_number;

	if ((stack == NULL) || (*stack == NULL))
	{
		printf("\n");
	}
	else
	{
		while (top_node != NULL)
		{
			if ((top_node->n > 0) && (isascii(top_node->n)))
			{
				printf("%c", top_node->n);
				top_node = top_node->next;
			}
			else
			{
				break;
			}
		}
		printf("\n");
	}
}
