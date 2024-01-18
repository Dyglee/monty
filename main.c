#define _POSIX_C_SOURCE 200809L
#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *file_stream;
    stack_t *stack_head = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file_stream = fopen(argv[1], "r");
    if (file_stream == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file_stream) != -1)
    {
        line_number++;
        process_line(&stack_head, line_number, line);
    }

    free(line);
    fclose(file_stream);
    free_stack_nodes(stack_head);

    return 0;
}

