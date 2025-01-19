#include "../headers/handle_waves.h"
#include <stdio.h>
#include <stdlib.h>
#define RED "\033[0;31m"
#define RESET "\033[0m"

void handle_waves(char *cmd)
{
    char filename[100];
    sscanf(cmd, "waves %s", filename);

    if (remove(filename) == 0)
    {
        printf(RED "File '%s' deleted successfully.\n" RESET, filename);
    }
    else
    {
        perror("Error deleting file");
    }
}
