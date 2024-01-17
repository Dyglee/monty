#include "monty.h"

/**
 * process_line - Process a line of input from the script file.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void process_line(stack_node **stack_head, unsigned int line_number)
{
    char *token;
    int num;
    size_t token_len;
    char *line_copy;

    token = strtok(global.line_content, " \t\n");
    if (token == NULL)
        return;

    line_copy = (char *)malloc(strlen(global.line_content) + 1);
    if (line_copy == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    strcpy(line_copy, global.line_content);

    token = strtok(line_copy, " \t\n");

    if (strcmp(token, "push") == 0)
    {
        token = strtok(NULL, " \t\n");
        if (token == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        token_len = strlen(token);
        if (token_len > 0 && token[token_len - 1] == '\n')
            token[token_len - 1] = '\0';

        if (!is_number(token))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        num = atoi(token);
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

    free(line_copy);
}

