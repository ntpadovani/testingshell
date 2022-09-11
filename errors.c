#include "shell.h"

/**
 * errors - To manage errors. 
 * 
 * @argv: The name of the file.
 * @Input: What the user entered.
 * @LineCount: The line number.
 * 
 * Return: Void
 */

void errors(char **argv, char *Input, int LineCount)
{
    printf("%s: %d: %s: not found\n", argv[0], LineCount, Input);    
}