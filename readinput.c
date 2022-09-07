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
	char *buffer = NULL, **commandinput = NULL;
	size_t size = 0;
	int usrinput = 1;

	(void) argc;
	(void) argv;

	printf("$: ");
	while ((usrinput = getline(&buffer, &size, stdin)) > 0)
	{	
		if (_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			buffer = NULL;
			exit(0);
		}
		if (_strcmp(buffer, "env\n") == 0)
		{
			_printenv(env);
			free(buffer);
			buffer = NULL;
			printf("$: ");
			continue;
		}
		commandinput = separate(buffer, " \n"); /*tokenize*/
		spawn_process(commandinput, env);
		size = 0;
		free(buffer);
		buffer = NULL;
		/*arrayfree(commandinput);*/
		commandinput = NULL;
		printf("$: ");
	}

	arrayfree(commandinput);
	commandinput = NULL;
	free(buffer);
	buffer = NULL;
	return (0);
} /*end*/
