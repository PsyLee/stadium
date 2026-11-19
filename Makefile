CC ?= gcc
TARGET := primer
SOURCES := src/main.c src/renderer.c src/camera.c src/lighting.c \
 src/geometry/pitch.c src/geometry/stands.c src/geometry/goals.c \
 src/geometry/seats.c src/geometry/stadium.c src/utils/image.c
OBJECTS := $(SOURCES:.c=.o)
CPPFLAGS ?= -Isrc -Isrc/geometry -Isrc/utils
CFLAGS ?= -O2 -Wall -Wextra
LDLIBS := -lglut -lGLU -lGL -lm
.PHONY: all clean test
all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
src/renderer.o: src/geometry/geometry.h src/lighting.h src/utils/image.h
src/camera.o: src/camera.h src/renderer.h
src/lighting.o: src/lighting.h
src/geometry/%.o: src/geometry/geometry.h src/renderer.h
src/utils/image.o: src/utils/image.h
tests/test_image: tests/test_image.c src/utils/image.c src/utils/image.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ tests/test_image.c src/utils/image.c
test: tests/test_image
	./tests/test_image
clean:
	rm -f $(OBJECTS) primer tests/test_image
