CC=g++
CFLAGS=-g -c -Wall

UNAME:= $(shell uname)
ifeq ($(UNAME), Linux)
LDFLAGS=-L./GameFramework -lGameFramework -lSDLmain -lSDL -lGL -lSDL_image -lSDL_ttf
else ifeq ($(UNAME), Darwin)
LDFLAGS=-framework OpenGL -framework SDL -framework SDL_image -framework cocoa -lSDLmain -L./GameFramework -lGameFramework -lSDL_ttf
else
LDFLAGS=-LC:\Windows\SDL-1.2.14\lib -L.\GameFramework -lGameFramework -lmingw32 -lSDLmain -lSDL -lopengl32 -lglu32 -lSDL_image
endif

ifeq ($(UNAME), Linux)
INCLUDES=-I../include/GameFramework/ -I../include/
else ifeq ($(UNAME), Darwin)
INCLUDES=-I../include/GameFramework/ -I../include/ -F/Library/Frameworks/ -I/Library/Frameworks/SDL.framework/Headers -I/Library/Frameworks/SDL_image.framework/Headers -I/Library/Frameworks/SDL_ttf.framework/Headers
else
INCLUDES=-I.\..\include\GameFramework -I.\..\include -IC:\Windows\SDL-1.2.14\include\SDL -IC:\Windows\SDL-1.2.14\lib
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

