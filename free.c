#include "shell.h"

/**
 *
 *
 *
 */

void arrayfree(char **string)
{
	int idx;
	for(idx = 0; string[idx] != NULL; idx++)
	{
		free(string[idx]);
	}
}
