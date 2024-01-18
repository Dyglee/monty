#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void add(stack_t **stack_head, unsigned int line_number)
{
    stack_t *temp;
    int sum;

    if (*stack_head == NULL || (*stack_head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack_head;
    sum = temp->n + temp->next->n;
    temp->next->n = sum;

    *stack_head = temp->next;
    free(temp);
}

