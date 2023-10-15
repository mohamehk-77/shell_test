#include "simple_shell.h"
/**
 * _arguments - split func
 * @input:
 * Return:
*/
char **_arguments()
{
    int args_m = 10;
    char *tokens, input;
    int num = 0;
    char **args = (char **)malloc(sizeof(char *) * args_m);

    if (args == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    tokens = strtok(input, " \n");

    while (tokens != NULL)
    {
        args[num] = strdup(tokens);

        if (args[num] == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        num++;

        if (num == args_m)
        {
            args_m *= 2;
            args = (char **)realloc(args, sizeof(char *) * args_m);

            if (args == NULL)
            {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
        }
        tokens = strtok(NULL, " \n");
    }

    args[num] = NULL;

    return args;
}
