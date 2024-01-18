#include "monty.h"

void print_all(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node = *stack_head;
    (void)line_number;

    while (current_node)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}

