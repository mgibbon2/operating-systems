# Directory for header files
IDIR =../include
# C compiler
CC=gcc
# Compiler flags, -Wall enables warnings
CFLAGS=-Wall
# Object file directory
ODIR=obj

# List of header files
_DEPS = list.h
# Appends all header file paths in _DEPS
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# List of object files
_OBJ = list.o list_test.o
# Appends all object file paths in _OBJ
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Builds object files from source files
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Builds the executable named "list_test" from the object files
list_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# 'clean' is a phony target, so no file is represented
.PHONY: clean
# Cleans up object files and executables
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~