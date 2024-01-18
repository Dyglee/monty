#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void swap(stack_t **stack_head, unsigned int line_number)
{
    stack_t *first, *second;

    if (*stack_head == NULL || (*stack_head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    first = *stack_head;
    second = first->next;

    /* Swapping process */
    first->next = second->next;
    first->prev = second;
    second->prev = NULL;
    second->next = first;

    if (first->next != NULL)
        first->next->prev = first;

    *stack_head = second;
}

