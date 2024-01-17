#include "monty.h"

/**
 * print_all - Prints all the values on the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void print_all(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node = *stack_head;

    (void)line_number;

    while (current_node)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}

/**
 * print_top - Prints the value at the top of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void print_top(stack_t **stack_head, unsigned int line_number)
{
    if (*stack_head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        fclose(global.file_stream);
        free(global.line_content);
        free_stack_nodes(*stack_head);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack_head)->n);
}

/**
 * pop_element - Removes the top element of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void pop_element(stack_t **stack_head, unsigned int line_number)
{
    stack_t *temp;

    if (*stack_head == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        fclose(global.file_stream);
        free(global.line_content);
        free_stack_nodes(*stack_head);
        exit(EXIT_FAILURE);
    }

    temp = *stack_head;
    *stack_head = temp->next;
    free(temp);
}

/**
 * swap_top_two - Swaps the top two elements of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void swap_top_two(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node;
    int stack_length = 0, temp;

    current_node = *stack_head;
    while (current_node)
    {
        current_node = current_node->next;
        stack_length++;
    }

    if (stack_length < 2 || current_node == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        fclose(global.file_stream);
        free(global.line_content);
        free_stack_nodes(*stack_head);
        exit(EXIT_FAILURE);
    }

    current_node = *stack_head;
    temp = current_node->n;
    current_node->n = current_node->next->n;
    current_node->next->n = temp;
}
