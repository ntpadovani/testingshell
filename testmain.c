#include "shell.h"


int main(void)
{
char string1[40] = "/usr/bin:", string2[] = "ls", *allcon;

allcon = chkcmddir(string1, string2);;

printf("%s:\n", allcon);

return (0);
}
