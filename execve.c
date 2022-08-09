#include "shell.h"

/**
 * spawn_process - creates a child process and executes a command
 * @args: an array
 *
 * Return: 0 if process executed succesfully,
 */

int spawn_process(char *cmd[], char *s)
{
	char *result, *path;
	pid_t ppid;
	int status = 0, wstatus;

	path = _getpath(env);
	result = chkcmddir(path, s);
	ppid = fork();
	if (ppid == -1)
	{
		perror("Error: forking");
	}

	if (ppid == 0)
	{
		if (execve(s, cmd, NULL))
		{
			perror("Execve");
			exit(EXIT_FAILURE);
			/*status = 1;*/
			/*return (status);*/
		}
	}
	if (ppid > 0)
	{
		wait(&wstatus);
	}
	return (status);
}
