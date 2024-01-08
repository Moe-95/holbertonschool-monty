#include "monty.h"

global_t var;
/**
 *main - interpreter for Monty ByteCodes files
 *@argc: Number of parameters
 *@argv: Pointer to all the parameters
 *
 *Return: Always 0
 */
int main(int argc, char **argv)
{
size_t line_buf_size = 0;

var.getl_info = NULL;
var.stack_head = NULL;
var.n_lines = 0;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
var.fp_struct = fopen(argv[1], "r");
if (!var.fp_struct)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (getline(&var.getl_info, &line_buf_size, var.fp_struct) != EOF)
{
var.n_lines++;
if (line_validator(var.getl_info) == 1)
continue;
/*split_str(var.getl_info);*/
execute_opcode(split_str(var.getl_info));
}
free(var.getl_info);
handle_dlist_head(var.stack_head);
fclose(var.fp_struct);
return (EXIT_SUCCESS);
}
