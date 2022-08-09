#include "shell.h"

/**
 *separate - A function that splits a
 *            string and returns an array
 *            of each word of the string.
 *@string: The string containing the words.
 *@s: The delimiter.
 *Return:  An array for each word found inside the string.
 */

char **separate(char *string, const char *s)
{
	char *token = NULL, **darray = NULL;
	int size = 0, idx = 0;
	size = count_words(string);
	printf("size-%d-\n", size);
	darray = malloc(sizeof(char *) * size + 1);
	if (darray == NULL)
	{
		return NULL;
	}
	token = strtok(string, s);
	while (token != NULL)
	{
		darray[idx] = malloc(sizeof(char) * _strlen(token) + 1);
		if (darray[idx] == NULL)
		{
			arrayfree(darray);
			return (NULL);
		}
		darray[idx] = token;
		idx++;
		token = strtok(NULL, s);
	}
	return (darray);
} /*end bracket*/
