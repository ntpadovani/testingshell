#include "shell.h"


int main(int argc, char **argv, char **env)
{
char string2[] = "ls", *allcon, *path;

(void) argc;
(void) argv;
path = _getpath(env);
allcon = chkcmddir(path, string2);;

printf("%s:\n", allcon);

return (0);
}
