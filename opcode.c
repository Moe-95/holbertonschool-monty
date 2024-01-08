#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/**
 * push - adds a new node at the beginning of a stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode in the file
 * @arg: argument passed to the opcode
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
if (stack == NULL)
{
fprintf(stderr, "L%d: stack is NULL\n", line_number);
exit(EXIT_FAILURE);
}

stack_t *new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

if (!arg || (*arg && !isdigit(*arg)))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free(new_node);
exit(EXIT_FAILURE);
}

new_node->n = atoi(arg);
new_node->prev = NULL;

if (*stack != NULL)
{
new_node->next = *stack;
(*stack)->prev = new_node;
}

*stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the head of the stack
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

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}
