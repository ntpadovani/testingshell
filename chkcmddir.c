#include "shell.h"

/**
 *chkcmddir - A function that concatinates two strings and checks if
 *            the commands are inside the given directory.
 *@dirpath: Contains the directory to be concatinated with the command.
 *@cmdinput: Contains the command to be concatinated with the directory.
 *
 *Return: A string with the concatinated dir and command."
 */

char *chkcmddir(char *dirpath, char *cmdinput)
{
	int result = 0;
	int idx = 0;
	char *concatpathinput = NULL, *concatpathinputcopy = NULL, **tokenzarray = NULL, *slashconcatinput = NULL, *cln = ":", slash[30] = "/";
	struct stat cmdstr;

	tokenzarray = separate(dirpath, cln); /*tokenizing the directories path with :, **THIRD MEM ALLOC(TIMES 2)**/
	slashconcatinput = strcat(slash, cmdinput); /*concatenizing '/' with input*/
	while (tokenzarray[idx] != NULL)
	{
		concatpathinput = strcat(tokenzarray[idx], slashconcatinput); /*concatenizing directory paths with input*/
		result = stat(concatpathinput, &cmdstr); /*verifying that the input executes in the given paths*/
		if (result == 0)
		{
			concatpathinputcopy = strdup(concatpathinput); /*duplicating the concatpathinput contents to preserve the original*/
			arrayfree(tokenzarray);
			return (concatpathinputcopy);
		}
		idx++;
	}
	arrayfree(tokenzarray); /*EIGHT FREE*/
	tokenzarray = NULL; /***************/
	return NULL;
}
