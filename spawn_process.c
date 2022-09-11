#include "shell.h"

/**
 * spawn_process - creates a child process and executes a command
 * @cmdinput: an array with input.
 * @env: the env variable
 * Return: 0 if process executed succesfully,
 */

int spawn_process(char **CmdInput, char **env, char **argv, char *Input, int LineCount)
{
	char *DirPath = NULL, *ConcatPathInput = NULL;
	pid_t ppid;
	int wstatus = 0;
	struct stat CmdStr;

	if (stat(CmdInput[0], &CmdStr) == -1) /*validating that the input is executable*/
	{
		DirPath = _getpath(env);						   /*start the aquisition of path directories*/
		ConcatPathInput = chkcmddir(DirPath, CmdInput[0]); /*verifying each directory with the command that was input*/
		if (ConcatPathInput == NULL)
		{
			errors(argv, Input, LineCount);
			arrayfree(CmdInput);   
			CmdInput = NULL;	   /***************/
			free(DirPath);		   /****************/
			DirPath = NULL;		   /**************/
			free(ConcatPathInput); /******/
			return (0);
		}
		ppid = fork(); /*start the process duplication process*/
		if (ppid == -1)
		{
			perror("Error: forking");
		}

		if (ppid == 0)
		{
			if (execve(ConcatPathInput, CmdInput, env) == -1)
			{
				perror("Execve");
				exit(EXIT_FAILURE);
			}
		}
		if (ppid > 0)
		{
			wait(&wstatus);
			arrayfree(CmdInput);   /*NINTH FREE*/
			CmdInput = NULL;	   /***************/
			free(DirPath);		   /****************/
			DirPath = NULL;		   /**************/
			free(ConcatPathInput); /******/
		}

	} /*||||||||||||||||||FIRST IF||||||||||||||||||||||*/
	else
	{
		ppid = fork(); /*start the duplication process*/
		if (ppid == -1)
		{
			perror("Error: forking");
		}
		if (ppid == 0)
		{
			if (execve(CmdInput[0], CmdInput, env) == -1)
			{
				perror("Execve");
				exit(EXIT_FAILURE);
			}
		}
		if (ppid > 0)
		{
			wait(&wstatus);
			arrayfree(CmdInput);   /*NINTH FREE*/
			CmdInput = NULL;	   /***************/
			free(DirPath);		   /****************/
			DirPath = NULL;		   /**************/
			free(ConcatPathInput); /******/
		}

	}
	return (0);
}