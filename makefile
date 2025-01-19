# Define the compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Define the target executable
TARGET = oceanShells

# Define the source files
SRC = oceanShells.c src/handle_waves.c

# Define the object files (compiled .o files)
OBJ = $(SRC:.c=.o)

# Default target to build the program
all: $(TARGET)

# How to link the object files to create the final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# How to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
