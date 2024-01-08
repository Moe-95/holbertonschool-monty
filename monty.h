#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - functional data for project
 * @n_lines: lines counter
 * @stack_head: stack head
 * @fp_struct: file
 * @getl_info: line content
 * @node_data: data node number
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_s
{
FILE *fp_struct;
stack_t *stack_head;
char *getl_info;

int node_data;
unsigned int n_lines;

} global_t;

/* global Variable */
extern global_t var;

/* execute the matched opcode function */
void execute_opcode(char *opcode);

/* handle the head of a doubly linked list */
void handle_dlist_head(stack_t *head);

/* get the opcode and check if the argument of push is an integer */
char *split_str(char *str_to_split);

/* helper functions */
void is_digit(char *number);
int line_validator(char *str);
size_t dlistint_len(stack_t *h);

/* opcode functions */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
