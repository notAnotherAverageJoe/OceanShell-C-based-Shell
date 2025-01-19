#include "../headers/handle_waves.h"
#include <stdio.h>
#include <stdlib.h>

void handle_waves(char *cmd)
{
    char filename[100];
    sscanf(cmd, "waves %s", filename);

    if (remove(filename) == 0)
    {
        printf("File '%s' deleted successfully.\n", filename);
    }
    else
    {
        perror("Error deleting file");
    }
}
