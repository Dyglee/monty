#include "monty.h"

/**
 * add_top_two - Adds the top two elements of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void add_top_two(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node;
    int stack_length = 0, sum;

    current_node = *stack_head;
    while (current_node)
    {
        current_node = current_node->next;
        stack_length++;
    }

    if (stack_length < 2 || current_node == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        fclose(global.file_stream);
        free(global.line_content);
        free_stack_nodes(*stack_head);
        exit(EXIT_FAILURE);
    }

    current_node = *stack_head;
    sum = current_node->n + current_node->next->n;
    current_node->next->n = sum;
    *stack_head = current_node->next;
    free(current_node);
}

/**
 * do_nothing - Does nothing.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void do_nothing(stack_t **stack_head, unsigned int line_number)
{
    (void)line_number;
    (void)stack_head;
}

/**
 * free_stack_nodes - Frees the stack.
 * @stack_head: Pointer to the head of the stack.
 */
void free_stack_nodes(stack_t *stack_head)
{
    stack_t *current_node;
    stack_t *next_node;

    current_node = stack_head;
    while (current_node != NULL)
    {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}

/**
 * add_node - Adds a new node to the stack.
 * @stack_head: Pointer to the head of the stack.
 * @n: Integer value to be pushed onto the stack.
 */

void add_node(stack_t **stack_head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        fclose(global.file_stream);
        free(global.line_content);
        free_stack_nodes(*stack_head);
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = *stack_head;
    new_node->prev = NULL;

    if (*stack_head != NULL)
    {
        (*stack_head)->prev = new_node;
    }

    *stack_head = new_node;
}

/**
 * add_queue - Adds a new node to the end of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @n: Integer value to be pushed onto the stack.
 */
void add_queue(stack_t **stack_head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    stack_t *current = *stack_head;
    if (new_node == NULL)
    {
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->next = NULL;
    if (*stack_head == NULL)
    {
        new_node->prev = NULL;
        *stack_head = new_node;
        return;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}
