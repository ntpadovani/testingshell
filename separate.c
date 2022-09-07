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
	char *tokenized = NULL, **darray = NULL;
	int size = 0, idx = 0;

	size = count_words(string);
	printf("The tokens size is:%d\n", size);
	if (size == 0)
	{
		return (darray);
	}
	darray = malloc(sizeof(char *) * (size + 1));
	if (darray == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	tokenized = strtok(string, s);
	while (tokenized != NULL)
	{
		darray[idx] = malloc(sizeof(char) * (strlen(tokenized) + 20));
		strcpy(darray[idx], tokenized);
		idx++;
		tokenized = NULL;
		tokenized = strtok(NULL, s);
	}
	darray[idx] = NULL;
	return (darray);
}
