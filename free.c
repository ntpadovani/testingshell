#include "shell.h"

/**
 * arrayfree - Used to free an array.
 *@array: The array to be freed.
 *
 * Return: Void
 */

void arrayfree(char **array)
{
	int idx;

	if(array == NULL)
	{
		return;
	}

	for (idx = 0; array[idx] != NULL; idx++)
	{
		free(array[idx]);
		array[idx] = NULL;
	}
	free(array);
	array = NULL;
}

