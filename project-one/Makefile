# C compiler
CC=gcc
# Compiler flags, -Wall enables warnings
CFLAGS=-Wall

# List of header files
HEADERS = list.h

# List of object files
OBJECTS = list.o list_test.o

# Builds object files from source files
%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Builds the executable named "list_test" from the object files
list_test: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

# Ensures 'run' and 'clean' are not seen as files
.PHONY: run clean

# Executes list_test
run: list_test
	./list_test

# Cleans up object files and executables
clean:
	rm -f *.o list_test