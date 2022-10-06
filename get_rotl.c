#include "monty.h"

/**
 * get_rotl - function that rotates the tail to the top
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 13. rotl
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		;
	}
	else
	{
		first = last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		*stack = first->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		(*stack)->prev = NULL;
	}
}
