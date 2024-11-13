# Compiler and flags
CC = gcc
CFLAGS = -Wimplicit-function-declaration
LDFLAGS = 
TARGET = main
OBJECTS = main.o

# Phony targets (not real files)
.PHONY: all clean clean_obj

# Default target
all: $(TARGET)

# Linking stage (builds the final executable)
$(TARGET): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $(TARGET)
	@chmod +x $(TARGET)

# Compilation stage (creates .o files)
%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

# Clean up all build artifacts
clean: 
	@rm -f $(TARGET) $(OBJECTS)

# Clean object files only (preserves executable)
clean_obj:
	@rm -f $(OBJECTS)
	@rm -f main.o
