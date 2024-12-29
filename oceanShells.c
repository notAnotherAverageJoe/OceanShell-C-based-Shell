#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BLUE "\033[0;34m"
#define TEAL "\033[0;36m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

// declaring functions
void execute_command(char *cmd);
void handle_tides(char *cmd);
void handle_waves(char *cmd);
void handle_inkit(char *cmd);
void handle_dive(char *cmd);
void handle_uhoh(void);
void handle_greet(void);
void handle_buoy(char *cmd);

// The main Kraken
int main()
{
    printf(GREEN "Welcome to OceanLife Shell\n" RESET);

    printf(GREEN "If you need support or general Q&A enter 'buoy'\n" RESET);
    char cmd[100];

    while (1)
    {
        printf(TEAL "OceanLife 🌊 -> " RESET);
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
    else if (strncmp(cmd, "dive", 4) == 0)
    {
        handle_dive(cmd);
    }
    else if (strncmp(cmd, "uhoh", 4) == 0)
    {
        handle_uhoh();
    }
    else if (strncmp(cmd, "greet", 5) == 0)
    {
        handle_greet();
    }
    // This is help & Q/A
    else if (strncmp(cmd, "buoy", 4) == 0)
    {
        handle_buoy(cmd);
    }
    else if (strcmp(cmd, "sink") == 0)
    {
        printf(BLUE "Exiting shell...\n" RESET);
        exit(0);
    }
    else
    {
        int status = system(cmd);
        if (status == -1)
        {
            perror(RED "Error executing command" RESET);
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
        perror(RED "Error creating file" RESET);
    }
    else
    {
        printf(GREEN "File '%s' created successfully.\n" RESET, filename);
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
    char filename[100] = {0};

    // extract the file name
    if (sscanf(cmd, "dive %s", filename) != 1)
    {
        printf("Error: Invalid command. Usage: dive <filename>\n");
        return;
    }

    printf("Filename parsed: '%s'\n", filename);

    if (filename[0] == '\0')
    {
        printf("Error: No filename specified.\n");
        return;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror(RED "Error opening file for reading" RESET);
        return;
    }

    printf("Contents of '%s':\n", filename);
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("%s", buffer); // Print each line from the file
    }

    fclose(file);
    printf("\nEnd of file reached.\n");
}
void handle_buoy(char *cmd)
{
    printf("Welcome to OceanLife -> support\n");
    printf("Are you stuck? to break free enter -> sink \n");
    printf("File creatoon -> tides 'filename.ext' \n");
}