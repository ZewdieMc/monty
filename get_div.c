#include "monty.h"

/**
 * get_div - function that divides the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 7. div
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_div(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		first = *stack;
		second = first->next;
		second->n /= first->n;
		*stack = second;
		(*stack)->prev = NULL;
		free(first);
	}
}
