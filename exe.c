#include "simple_shell.h"
/**
 * 
 * 
*/
void start_procss(char *input)
{
    int process, i;
    char *token;
    int y = 0;
    char **ptr = malloc(sizeof(char *) * 3);
    pid_t child;
    token = strtok(input, " ");
    while (token != NULL)
    {
        ptr[y] = strdup(token);
        if (ptr[y] == NULL)
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        y++;
        token = strtok(NULL, " \n");
    }
    ptr[y] = NULL;

    child = fork();
    if (child == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child == 0)
    {
        if (execve(ptr[0], ptr, NULL) == -1)
        {
            perror("./shell");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&process);
    }
    for (i = 0; i < y; i++)
    {
        free(ptr[i]);
    }
    free(ptr);
}
