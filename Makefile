CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g
SOURCES := $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET = myprog 
FORMAT = clang-format

.PHONY: clean
.PHONY: format

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)

format:
	clang-format --style=file -i $(SOURCES)
