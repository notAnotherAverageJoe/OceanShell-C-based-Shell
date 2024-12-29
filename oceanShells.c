#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

// Function declarations
void execute_command(char *cmd);
void handle_tides(char *cmd);
void handle_waves(char *cmd);
void handle_inkit(char *cmd);
void handle_dice(char *cmd);
void handle_uhoh(void);
void handle_greet(void);

// Main function
int main()
{
    char cmd[100];

    while (1)
    {
        printf("OceanLife 🌊 -> ");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = 0;

        if (strcmp(cmd, "exit") == 0)
        {
            break;
        }

        execute_command(cmd);
    }

    return 0;
}

void execute_command(char *cmd)
{
    if (strncmp(cmd, "tides", 5) == 0)
    {
        handle_tides(cmd);
    }
    else if (strncmp(cmd, "waves", 5) == 0)
    {
        handle_waves(cmd);
    }
    else if (strncmp(cmd, "inkit", 5) == 0)
    {
        handle_inkit(cmd);
    }
    else if (strncmp(cmd, "uhoh", 4) == 0)
    {
        handle_uhoh();
    }
    else if (strncmp(cmd, "greet", 5) == 0)
    {
        handle_greet();
    }
    else if (strcmp(cmd, "exit") == 0)
    {
        printf("Exiting shell...\n");
        exit(0);
    }
    else
    {
        int status = system(cmd);
        if (status == -1)
        {
            perror("Error executing command");
        }
    }
}
void handle_tides(char *cmd)
{
    char filename[100];
    sscanf(cmd, "tides %s", filename);

    int fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("Error creating file");
    }
    else
    {
        printf("File '%s' created successfully.\n", filename);
        close(fd);
    }
}

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

void handle_inkit(char *cmd)
{
    char filename[100];
    sscanf(cmd, "inkit %s", filename);

    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        perror("Error opening file for writing");
        return;
    }

    printf("Enter the content to write to '%s' (end input with an empty line):\n", filename);

    char buffer[256];
    while (1)
    {
        fgets(buffer, sizeof(buffer), stdin);

        if (buffer[0] == '\n')
            break;

        fputs(buffer, file);
    }

    fclose(file);
    printf("Content written to '%s' successfully.\n", filename);
}

void handle_uhoh(void)
{
    printf("Codes that bad huh?... I will delete it for you then!\n\n");
    printf("All data stored on the C drive has been removed! Have a wonderful day\n");
}

void handle_greet(void)
{
    printf("Welcome to my humble Ocean Shell🌊\n\n");
    printf("Have a wonderful day\n");
}

void handle_dive(char *cmd)
{
    char filename[150]
}