CC      := cc
CFLAGS  := -Wall -Wextra -std=c11 -O2
LDFLAGS := $(shell pkg-config --libs raylib)
INCLUDES:= $(shell pkg-config --cflags raylib)

TARGET  := app
SRC     := main.c
OBJ     := $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

