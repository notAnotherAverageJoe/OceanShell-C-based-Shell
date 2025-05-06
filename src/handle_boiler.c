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

    char *ext = strrchr(filename, '.');
    if (!ext)
    {
        printf("Error: No file extension found. \n");
        return;
    }

    FILE *file = fopen(filename, "w");
    if (!file)
    {
        perror("Error creating file");
        return;
    }
    // extension based boilerplate
    if (strcmp(ext, ".c") == 0)
    {
        fprintf(file, "#include <stdio.h>\n\nint main() {\n    printf(\"Hello, world!\\n\");\n    return 0;\n}\n");
    }
    else if (strcmp(ext, ".py") == 0)
    {
        fprintf(file, "#!/usr/bin/env python3\n\nprint(\"Hello, world!\")\n");
    }
    else if (strcmp(ext, ".js") == 0)
    {
        fprintf(file, "console.log(\"Hello, world!\");\n");
    }
    else if (strcmp(ext, ".html") == 0)
    {
        fprintf(file, "<!DOCTYPE html>\n<html>\n<head><title>Boilerplate</title></head>\n<body>\n<h1>Hello, world!</h1>\n</body>\n</html>\n");
    }
    else
    {
        fprintf(file, "// Boilerplate for %s not available\n", ext);
    }

    fclose(file);
    printf("Boilerplate created in '%s'.\n", filename);
}