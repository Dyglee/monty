#include "monty.h"

void process_line(stack_t **stack_head, unsigned int line_number)
{
    char *token, *arg;
    int num;

    token = strtok(global.line_content, " \t\n");
    if (token == NULL)
        return;

    while (isspace(*token))
        token++;

    if (*token == '\0')
    {
        fprintf(stderr, "L%d: missing opcode\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (strcmp(token, "push") == 0)
    {
        arg = strtok(NULL, " \t\n");
        if (arg == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        while (isspace(*arg))
            arg++;

        if (*arg == '\0')
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        num = atoi(arg);
        push_element(stack_head, num);
    }
    else if (strcmp(token, "pall") == 0)
    {
        print_all(stack_head, line_number);
    }
    else if (strcmp(token, "pint") == 0)
    {
        print_top(stack_head, line_number);
    }
    else if (strcmp(token, "swap") == 0)
    {
        swap_top_two(stack_head, line_number);
    }
    else if (strcmp(token, "add") == 0)
    {
        add_top_two(stack_head, line_number);
    }
    else if (strcmp(token, "nop") == 0)
    {
        do_nothing(stack_head, line_number);
    }
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
        exit(EXIT_FAILURE);
    }
}

