#include "../headers/handle_boilers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handle_boilers(char *cmd)
{
    char filename[100];
    if (sscanf(cmd, "boiler %s", filename) != 1)
    {
        printf("Usage: boilers <filename.ext>\n");
        return;
    }
}