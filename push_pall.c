#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n\t");
	int n;

	if (!arg || !isdigit(*arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	if (add_node(stack, n) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
