#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"monty.h"

char *command_arg;

/**
 * push - adds a new node at the beginning of a stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
if (!command_arg || (*command_arg && !isdigit(*command_arg)))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

stack_t *new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = atoi(command_arg);
new_node->prev = NULL;

if (*stack)
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

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}
