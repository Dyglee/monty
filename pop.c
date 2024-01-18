#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void pop(stack_t **stack_head, unsigned int line_number)
{
    stack_t *temp;

    if (*stack_head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack_head;
    *stack_head = temp->next;
    if (*stack_head != NULL)
        (*stack_head)->prev = NULL;

    free(temp);
}

