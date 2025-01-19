#include <stdlib.h>
#include <fcntl.h>
#include <linux/stat.h>
#include <sys/stat.h>
#include "../headers/handle_tides.h"
#include <stdio.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

void handle_tides(char *cmd)
{
    char filename[100];
    sscanf(cmd, "tides %s", filename);

    int fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror(RED "Error creating file" RESET);
    }
    else
    {
        printf(GREEN "File '%s' created successfully.\n" RESET, filename);
        close(fd);
    }
}