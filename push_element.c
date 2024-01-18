#include "monty.h"

void push_element(stack_t **stack_head, unsigned int line_number, char *arg)
{
    int num;

    if (!is_number(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        free_stack_nodes(*stack_head);
        exit(EXIT_FAILURE);
    }

    num = atoi(arg);
    add_node(stack_head, num);
}

