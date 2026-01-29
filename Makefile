C      := cc
CFLAGS  := -Wall -Wextra -std=c11 -O2

RAYLIB_LIBS    := $(shell pkg-config --libs raylib)
RAYLIB_CFLAGS := $(shell pkg-config --cflags raylib)

X11_LIBS      := $(shell pkg-config --libs x11 xrandr)
X11_CFLAGS    := $(shell pkg-config --cflags x11 xrandr)

LDFLAGS  := $(RAYLIB_LIBS) $(X11_LIBS)
INCLUDES := $(RAYLIB_CFLAGS) $(X11_CFLAGS)

TARGET  := app
SRC     := main.c xwindow.c 
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
