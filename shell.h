#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>

/*Defined type structs*/

/**
* type - A struct function.
* 
* @data: The variable containing the 
*        left side letter in our
*        2d array structure.
* @f:    It points to the function on the right
*        side of  our 2d array structure.
*/
typedef struct type
{
        char data;
        int (*f)(va_list ptr);
} escoge_t;
/*Defined type structs end*/

/*From here on below, the function prototypes*/
char **separate(char *string,const char *s);
int count_words(char *string);
int _strlen(char *s);
char *chkcmddir(char *strone, char *strtwo);
char *_getpath(char **envp);
int _strcmp(char *s1, char *s2);
int _printenv(char **env);
void arrayfree(char **string);
int spawn_process(char **CmdInput, char **env, char **argv, char *Input, int LineCount);
void errors(char **argv, char *Input, int LineCount);
#endif
