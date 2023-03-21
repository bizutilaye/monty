#include "monty.h"
/**
 * op_add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the Monty file
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int n1;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	n1 = (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n += n1;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
