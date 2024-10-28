CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g
SOURCES := $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET = myprog 

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)
