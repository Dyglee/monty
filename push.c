#include "monty.h"

/**
 * push_element - Pushes an element to the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void push_element(stack_node **stack_head, unsigned int line_number)
{
    int n, j = 0, flag = 0;

    if (global.argument)
    {
        if (global.argument[0] == '-')
            j++;
        for (; global.argument[j] != '\0'; j++)
        {
            if (global.argument[j] > 57 || global.argument[j] < 48)
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(global.file_stream);
            free(global.line_content);
            free_stack_nodes(*stack_head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(global.file_stream);
        free(global.line_content);
        free_stack_nodes(*stack_head);
        exit(EXIT_FAILURE);
    }
    n = atoi(global.argument);
    if (global.mode_flag == 0)
        add_node(stack_head, n);
    else
        add_queue(stack_head, n);
}
