#include"monty.h"
char *command_arg = NULL;
/**
 * push - pushes a node to the top of stack
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 * @arg: arguments
 * Return: Nothing.
 */
void push(stack_t** stack, unsigned int line)
{
stack_t* node = NULL;

if (stack == NULL)
{
fprintf(stderr, "L%d: Error stack not found\n", line);
exit(EXIT_FAILURE);
}

node = malloc(sizeof(stack_t));

if (node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
free_stack(stack);
exit(EXIT_FAILURE);
}

node->n = atoi(command_arg);
node->prev = NULL;
node->next = *stack;

if (*stack)
(*stack)->prev = node;

(*stack) = node;
}

/**
 * pall - prints the data of all nodes in stack
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 * Return: Nothing.
 */
void pall(stack_t** stack, unsigned int line)
{
stack_t* temp;
(void)line;

temp = *stack;

while (temp)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}

/**
 * pint - prints the value at the top of stack
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 * Return: Nothing.
 */
void pint(stack_t** stack, unsigned int line)
{
stack_t* temp;

if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line);
exit(EXIT_FAILURE);
}

temp = *stack;
while (temp)
{
if (temp->prev == NULL)
break;
temp = temp->prev;
}
printf("%d\n", temp->n);
}

/**
 * pop - removes the top element of stack
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 * Return: Nothing.
 */
void pop(stack_t** stack, unsigned int line)
{
if (stack == NULL || *stack == NULL) {
fprintf(stderr, "L%d: can't pop an empty stack\n", line);
exit(EXIT_FAILURE);
}

if ((*stack)->next != NULL)
{
*stack = (*stack)->next;
free((*stack)->prev);
(*stack)->prev = NULL;
} else {
free(*stack);
*stack = NULL;
}
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 * Return: Nothing.
 */
void swap(stack_t** stack, unsigned int line)
{
int data;

if (stack == NULL || *stack == NULL || !((*stack)->next))
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line);
exit(EXIT_FAILURE);
}

data = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = data;
}
