#include "simple_shell.h"

int pprint_prompt()
{
    while (1)
    {
        char *x = NULL; /*Declare and allocate memory for x*/
        size_t size = MAXIMUM_INPUT;
        ssize_t read;

        write(STDOUT_FILENO, print_prompt, strlen(print_prompt));

        read = getline(&x, &size, stdin);
        if (read == -1)
        {
            if (feof(stdin))
            {
                break;
            }
            else
            {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        start_procss(x);

        /*Free memory allocated by getline*/
        free(x);
    }
    return 0;
}
