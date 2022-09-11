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
	char **grabpath = NULL, *grabpathcopy = NULL;

	for (idx = 0; envp[idx] != NULL ; idx++) /*start the search for PATH word within envp*/
	{
		
		if (strncmp(envp[idx], "PATH", 4) == 0) /*acknowledging we found the PATH word*/
		{
			/*printf("----------\nThis is ENVP:%s\n----------\n", envp[idx]); used for debugin*/
			grabpathcopy = strdup(envp[idx]); /*duplicating the envp contents to preserve the original*/
			grabpath = separate(grabpathcopy, "="); /*tokenizing the contents***2ND MEM ALLOC(TIMES 2)**/
			/*printf("----------\nThis is GRAB[1]:%s\n---------\n", grabpath[1]); used for debugin*/
			free(grabpathcopy); /*SEVENTH FREE*/
			grabpathcopy = strdup(grabpath[1]); /*duplicating the grabpath contents to preserve the original*/
			arrayfree(grabpath);
			return (grabpathcopy);
		}
	
	}
	return (NULL);
}

