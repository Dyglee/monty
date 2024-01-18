#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void pint(stack_t **stack_head, unsigned int line_number)
{
    if (*stack_head == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack_head)->n);
}

