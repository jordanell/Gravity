CC=g++
CFLAGS=-c -Wall

UNAME:= $(shell uname)
ifeq ($(UNAME), Linux)
LDFLAGS=-lSDLmain -lSDL -lGL -lSDL_image -L./GameFramework -lGameFramework
endif
ifeq ($(UNAME), Darwin)
LDFLAGS=-framework OpenGL -framework SDL -framework SDL_image -framework cocoa -lSDLmain -L./GameFramework -lGameFramework
endif

ifeq ($(UNAME), Linux)
INCLUDES=-I../include/GameFramework/ -I../include
endif
ifeq ($(UNAME), Darwin)
INCLUDES=-I../include/GameFramework/ -I../include/ -F/Library/Frameworks/ -I/Library/Frameworks/SDL.framework/Headers -I/Library/Frameworks/SDL_image.framework/Headers
endif

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Game

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(INCLUDES) $(OBJECTS) -o ../bin/$@ $(LDFLAGS)

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

