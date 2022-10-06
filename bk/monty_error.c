#include "monty.h"

void monty_error(monty_t *monty){
  switch (monty->error) {
  case MONTY_ERROR_INVALID_OPCODE:
			printf("L%d: unknow instruction %s\n", monty->line, monty->token);
			break;
		case MONTY_ERROR_PUSH_MISSING_ARG:
		case MONTY_ERROR_PUSH_INVALID_ARG:
			printf("L%d: usage push integer\n", monty->line);
			break;
		case MONTY_ERROR_POP_EMPTY:
			printf("L%d: can't pop an empty stack\n", monty->line);
			break;		
		case MONTY_ERROR_PINT_EMPTY:
			printf("L%d: can't %s, stack empty\n", monty->line, monty->token);
			break;
default:
			printf("L%d: unknown error\n", monty->line);
	}
}
