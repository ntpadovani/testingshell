#include "shell.h"

/**
*_printenv - Prints the enviroment info.
*@env: Contains the enviroment info.
*
*Return: Prints on the stdout the enviroment info.
*/

int _printenv(char **env)
{
int idx = 0;
	for (; env[idx] != NULL; idx++)
	{
		_printf("%s\n", env[idx]);
	}
return (0);
}
