#include "shell.h"

/**
 *_getpath - grabs the string of the path
 *@envp - array of enviromentanl value which is path
 * with directories
 * Return: pointer to path or NULL
 */

char *_getpath(char **envp)
{
	int idx;
	char **grab = NULL, *grabcopy = NULL;

	for (idx = 0; envp[idx] != NULL ; idx++)
	{
		
		if (strncmp(envp[idx], "PATH", 4) == 0)
		{
			printf("----------\nThis is ENVP:%s\n----------\n", envp[idx]);
			grabcopy = strdup(envp[idx]);
			grab = separate(grabcopy, "=");
			printf("----------\nThis is GRAB[1]:%s\n---------\n", grab[1]);
			free(grabcopy);
			free(grab[0]);
			return (grab[1]);
		}
	
	}
	return (NULL);
}

