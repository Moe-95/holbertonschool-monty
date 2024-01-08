#include "monty.h"

/**
 * line_validator - check whitespaces
 * @str: string for check
 *
 * Return: void
 */
int line_validator(char *str)
{
int index = 0, flag = 0, len = 0;

len = strlen(str);
while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
{
index++;
}

if (index == len)
flag = 1;

return (flag);
}

/**
 * is_digit - check is digit
 * @number: character for check
 *
 * Return: void
 */
void is_digit(char *number)
{
unsigned int i = 0;

if (number == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", var.n_lines);
free(var.getl_info);
handle_dlist_head(var.stack_head);
fclose(var.fp_struct);
exit(EXIT_FAILURE);
}
else if (number[0] != '-' && (number[0] < 48 || number[0] > 57))
{
fprintf(stderr, "L%u: usage: push integer\n", var.n_lines);
free(var.getl_info);
handle_dlist_head(var.stack_head);
fclose(var.fp_struct);
exit(EXIT_FAILURE);
}
for (i = 1; number[i] != '\0'; i++)
{
if (number[i] < 48 || number[i] > 57)
{
fprintf(stderr, "L%u: usage: push integer\n", var.n_lines);
free(var.getl_info);
handle_dlist_head(var.stack_head);
fclose(var.fp_struct);
exit(EXIT_FAILURE);
}
}
}

/**
 * dlistint_len - returns the number of elements in a d linked list
 * @h: head of the linked list
 *
 * Return: the number of nodes
 */
size_t dlistint_len(stack_t *h)
{
size_t n_nodes = 0;

if (h == NULL)
{
return (0);
}
while (h != NULL)
{
h = h->next;
n_nodes++;
}
return (n_nodes);
}
