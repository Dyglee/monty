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
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
        free_stack_nodes(*stack_head);
        exit(EXIT_FAILURE);
    }
}

