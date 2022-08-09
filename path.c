#include "shell.h"

/**
 *_getpath - grabs the string of the path
 *@envp - array of enviromentanl value which is path
 * with directories
 * Return: pointer to path or NULL
 */

char *_getpath(char **envp)
{
	int i = 0;
	char **grab;

	for (; envp[i] != NULL ; i++)
	{
		grab = separate(envp[i], "=");
		if (strcmp(grab[0], "PATH") == 0)
		{
			return (grab[1]);
		}
	}
	return (NULL);
}

