#include "monty.h"

void process_line(stack_t **stack_head, unsigned int line_number, char *line)
{
    char *token, *arg;

    token = strtok(line, " \t\n");
    if (token == NULL)
        return;

    if (strcmp(token, "push") == 0)
    {
        arg = strtok(NULL, " \t\n");
        push_element(stack_head, line_number, arg);
    }
    else if (strcmp(token, "pall") == 0)
    {
        print_all(stack_head, line_number);
    }
        else if (strcmp(token, "pint") == 0)
    {
        pint(stack_head, line_number);
    }
    else if (strcmp(token, "pop") == 0)
    {
        pop(stack_head, line_number);
    }
    else if (strcmp(token, "swap") == 0)
    {
        swap(stack_head, line_number);
    }
    else if (strcmp(token, "add") == 0)
    {
        add(stack_head, line_number);
    }
    else if (strcmp(token, "nop") == 0)
    {
        nop(stack_head, line_number);
    }
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
        free_stack_nodes(*stack_head);
        exit(EXIT_FAILURE);
    }
}

