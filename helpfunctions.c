#include "monty.h"

/* Checks if a string is a number */
int is_number(char *str)
{
    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

/* Frees nodes of the stack */
void free_stack_nodes(stack_t *stack_head)
{
    stack_t *current_node;

    while (stack_head != NULL)
    {
        current_node = stack_head;
        stack_head = stack_head->next;
        free(current_node);
    }
}

/* Adds a node to the stack */
void add_node(stack_t **stack_head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack_nodes(*stack_head);
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = *stack_head;
    new_node->prev = NULL;

    if (*stack_head != NULL)
    {
        (*stack_head)->prev = new_node;
    }

    *stack_head = new_node;
}

