#include "shell.h"

/**
 *chkcmddir - A function that concatinates two strings and checks if
 *            the commands are inside the given directory.
 *@strone: Contains the directory to be concatinated with the command.
 *@strtwo: Contains the command to be concatinated with the directory.
 *
 *Return: A string with the concatinated dir and command."
 */

char *chkcmddir(char *strone, char *strtwo)
{
	int result = 0;
	int idx = 0;
	char *constr = NULL, **tokenz = NULL, *slashcon = NULL, *cln = ":", slash[] = "/";
	struct stat cmdstr;

	tokenz = separate(strone, cln);
	slashcon = strcat(slash, strtwo);
	while (tokenz[idx] != NULL)
	{
		constr = strcat(tokenz[idx], slashcon);
		result = stat(constr, &cmdstr);
		if (result == 0)
		{
			return (constr);
		}
		idx++;
	}
	return NULL;
}
