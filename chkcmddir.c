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
	/*int length = 0, length2 = 0;*/
	int result = -1, idx = 0, idx2 = 0;
	char *constr = NULL, **tokenz = NULL, *slashcon = NULL, *cln = ":", slash[] = "/";
	struct stat cmdstr;
	
	/*strtwo = "hola";*/
	tokenz = separate(strone, cln);

	/*length = _strlen(strtwo);*/
	/*printf("(chkcnddir)length:%d", length);*/
	slashcon = strcat(slash, strtwo);
	printf("(chkcmddir)strtwo-%s\n", strtwo);
	printf("(chkcmddir)-%s\n", slashcon);
	for(; tokenz[idx2] != NULL; idx2++)
	{
		printf("(chkcmddir)-%s\n", tokenz[idx2]);
	}
	/*length2 = _strlen(slashcon);*/
	while (result == -1 || tokenz[idx] != NULL)
	{
		
		printf("im here %d\n", idx);
		/*length = _strlen(tokenz[idx]);*/
		/*length = ((length + length2) + 1);*/
		constr = malloc(1024);
		constr = strcat(tokenz[idx], slashcon);
		printf("hey sir %s\n", constr);
		result = stat(constr, &cmdstr);
		printf("----------------------------------------------\n");
		printf("Result from stat() %d\n", result);
		if (result == 0)
		{
			printf("RESULT:%s\n", constr);
			return (constr);
		}
		idx++;
	}
	exit(0);
}
