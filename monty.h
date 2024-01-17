#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct bus_s
{
    char *argument;
    FILE *file_stream;
    char *line_content;
    int mode_flag;
} global_vars;

extern global_vars global;

typedef struct instruction_s
{
    char *opcode;
    void (*handler)(stack_t **stack, unsigned int line_number);
} instruction;

void push_element(stack_t **stack_head, unsigned int line_number);
void print_all(stack_t **stack_head, unsigned int line_number);
void print_top(stack_t **stack_head, unsigned int line_number);
void swap_top_two(stack_t **stack_head, unsigned int line_number);
void add_top_two(stack_t **stack_head, unsigned int line_number);
void do_nothing(stack_t **stack_head, unsigned int line_number);
void free_stack_nodes(stack_t *stack_head);
void add_node(stack_t **stack_head, int n);
void add_queue(stack_t **stack_head, int n);
void process_line(stack_t **stack_head, unsigned int line_number);
int is_number(char *str);
#endif /* MONTY_H */

