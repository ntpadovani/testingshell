#include "shell.h"

/**
 * spawn_process - creates a child process and executes a command
 * @args: an array
 *
 * Return: 0 if process executed succesfully,
 */

int spawn_process(char **cmd, char **env)
{
	char *path = NULL;
	pid_t ppid;
	int wstatus = 0;
	struct stat cmdstr;

	

	if(stat(cmd[0], &cmdstr) == -1)
	{		
		path = _getpath(env);
		cmd[0] = chkcmddir(path, cmd[0]);

	}
	ppid = fork();
	if (ppid == -1)
	{
		perror("Error: forking");
	}

	if (ppid == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
		{
			perror("Execve");
			exit(EXIT_FAILURE);
		}
	}
	if (ppid > 0)
	{
		wait(&wstatus);
		arrayfree(cmd);
		cmd = NULL;
		free(path);
		path = NULL;
	}
		
		return (0);
}
