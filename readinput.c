#include "shell.h"

/**
 *main - The primary function of our shell program.
 *@argc: The size of the argument array.
 *@argv: The arguments array.
 *@env: Contains the enviroment info.
 *
 *Return: It it based on what the user inputs.
 */


int main(int argc, char **argv, char **env)
{
	char *buffer = NULL, **commandinput = NULL, *path = NULL;
	size_t size = 0;
	int usrinput = 1, idx;

	(void) argc;
	(void) argv;

	_printf("$: ");
	while ((usrinput = getline(&buffer, &size, stdin)) > 0)
	{	
		if (_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			exit(0);
		}
		if (_strcmp(buffer, "env\n") == 0)
		{
			_printenv(env);
			_printf("$: ");
			continue;
		}
		commandinput = separate(buffer, " \n"); /*tokenize*/
		spawn_process(commandinput, result);
		size = 0;
		buffer = NULL;
		printf("$: ");
	}
	printf("after the loop-\n");
	free(buffer);
	return (0);
} /*end*/
