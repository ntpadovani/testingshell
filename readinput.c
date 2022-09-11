#include "shell.h"

/**
 *main - The primary function of our shell program.
 *@argc: The size of the argument array.
 *@argv: The arguments array.
 *@env: Contains the enviroment info.
 *
 *Return: It is based on what the user inputs.
 */
void sig_handler(int signum){
	(void) signum;
}

int main(int argc, char **argv, char **env)
{
	char *Input = NULL, **CmdInput = NULL;
	size_t SizeOfInput = 0;
	int InputForCndt = 1, LineCount = 0;

	(void) argc;
	(void) argv;

	signal(SIGINT,sig_handler);
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("$: ");
	}
	while ((InputForCndt = getline(&Input, &SizeOfInput, stdin)) > 0)
	{	
		LineCount++;
		if (Input[0] == '\n')/*if there is a blank line, ignore it, even if it has spaces*/
        {
            free(Input); 
			Input = NULL;
			printf("$: ");
			continue;
        }
		if (_strcmp(Input, "exit\n") == 0)
		{
			free(Input); /*FIRST FREE*/
			Input = NULL; /**********/
			exit(0);
		}
		if (_strcmp(Input, "env\n") == 0)
		{
			_printenv(env);
			free(Input); /*SECOND FREE*/
			Input = NULL;/***********/
			printf("$: ");
			continue;
		}
		CmdInput = separate(Input, " \n"); /*start of the tokenizing process, **1ST MEM ALLOC(TIMES 2)**/
		spawn_process(CmdInput, env, argv, Input, LineCount); /*start of the path directory search process*/
		SizeOfInput = 0; /*reseting values to zero for variables not needed any more at the moment*/
		free(Input); /*THIRD FREE*/
		Input = NULL; /**********/
		/*arrayfree(cmdinput);*/
		CmdInput = NULL; /******/
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("$: ");
		}
	}

	arrayfree(CmdInput); /*FOURTH FREE*/
	CmdInput = NULL; /****************/
	free(Input); /*******************/
	Input = NULL; /*****************/
	return (0);
} /*end bracket*/
