# Makefile to compile and run the program

# Executable name
EXECUTABLE = lut

# Source files list
SOURCES = main.c LUT.c

# Compiler options
CFLAGS = -Wall -Wextra -lm

# Compilation command
$(EXECUTABLE): $(SOURCES)
	gcc $(SOURCES) -o $(EXECUTABLE) $(CFLAGS)

# Command to run the compiled program
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Command to clean generated files
clean:
	rm -f $(EXECUTABLE)
