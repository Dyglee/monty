#define _POSIX_C_SOURCE 200809L

#include "monty.h"

global_vars global;

int main(int argc, char *argv[])
{
    stack_t *stack_head = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    global.file_stream = fopen(argv[1], "r");
    if (global.file_stream == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, global.file_stream) != -1)
    {
        line_number++;
        global.line_content = line;
        process_line(&stack_head, line_number);
    }

    free(line);
    fclose(global.file_stream);
    free_stack_nodes(stack_head);

    return 0;
}

