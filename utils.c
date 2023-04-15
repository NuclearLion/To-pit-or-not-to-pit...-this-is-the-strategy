#include "utils.h"

int hash(char *command)
{
    if (strcmp(command, "print") == 0)
        return 0;
    
    if (strcmp(command, "analyze") == 0)
        return 1;
    
    if (strcmp(command, "clear") == 0)
        return 2;

    if (strcmp(command, "exit") == 0)
        return 3;

    return -1;
}
