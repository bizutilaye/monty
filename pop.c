#include "monty.h"
/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being interpreted from script file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(temp);
}
