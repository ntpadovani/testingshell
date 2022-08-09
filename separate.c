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
	printf("(separate)string:%s\n", string); 
	size = count_words(string);
	printf("(separate)under size:%d\n", size);
	darray = malloc(sizeof(char *) * size + 1);
	printf("(separate)under darray\n");
	if (darray == NULL)
	{
		exit(-1);
	}
	token = strtok(string, s);
	printf("(separate)under token 1sttok:%s\n", token);
	while (token != NULL)
	{
		darray[idx] = malloc(sizeof(char) * _strlen(token) + 1);
		if (darray == NULL)
		{
			free(darray);
			return (darray);
		}
		printf("(separate)inside the loop:%s\n", token);
		darray[idx] = token;
		idx++;
		token = strtok(NULL, s);
		printf("(separate)under token 2ndtok:%s\n", token);
	}
	printf("(separate)got out of loop:%s\n", darray[0]);
	return (darray);
} /*end bracket*/
