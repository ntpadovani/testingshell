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
int _printf(const char *format, ...);
int print_char(va_list prt);
int print_string(va_list ptr);
int print_number(va_list ptr);
int print_int(int n); 
int spawn_process(char *cmd[], char *s);
char *_strncat(char *dest, char *src, int n);
char *chkcmddir(char *strone, char *strtwo);
char *_getpath(char **envp);
int _strcmp(char *s1, char *s2);
int _printenv(char **env);
#endif
