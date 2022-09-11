#include "shell.h"

/**
 *separate - A function that splits a
 *            string and returns an array
 *            of each word of the string.
 *@input: The string containing the words.
 *@delimiter: The delimiter used to tokenize.
 *Return:  An array for each word found inside the string.
 */

char **separate(char *Input, const char *Delimiter)
{
	char *TokenizedInput = NULL, **TokenArray = NULL;
	int TokenSize = 0, idx = 0;

	TokenSize = count_words(Input); /*start counting tokens found*/
	/*printf("The tokens size is:%d\n", tokensize); used to debug*/
	if (TokenSize == 0) /*if there are no tokens*/
	{
		return (TokenArray);
	}
	TokenArray = malloc(sizeof(char *) * (TokenSize + 1)); /*allocation of mem for the whole array*/
	if (TokenArray == NULL) /*if the process of allocation were to fail*/
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	TokenizedInput = strtok(Input, Delimiter); /*tokenize process*/
	while (TokenizedInput != NULL)
	{
		TokenArray[idx] = malloc(sizeof(char) * (strlen(TokenizedInput) + 20)); /*allocation of mem for each index array*/
		strcpy(TokenArray[idx], TokenizedInput); /*copy of every tokenizedinput to its own index array*/
		idx++;
		TokenizedInput = NULL; /*FIFTH FREE*/
		TokenizedInput = strtok(NULL, Delimiter);
	}
	TokenArray[idx] = NULL; /*SIXTH FREE*/
	return (TokenArray);
}
