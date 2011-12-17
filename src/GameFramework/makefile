CC=g++
CFLAGS=-g -c -Wall
LDFLAGS=-lSDLmain -lSDL -lGL -lSDL_image

UNAME:= $(shell uname)
ifeq ($(UNAME), Linux)
INCLUDES=-I../../include/GameFramework/
else ifeq ($(UNAME), Darwin)
INCLUDES=-I../../include/GameFramework/ -I../../include/ -F/Library/Frameworks/ -I/Library/Frameworks/SDL.framework/Headers -I/Library/Frameworks/SDL_image.framework/Headers
else
INCLUDES=-I.\..\..\include\GameFramework -I.\..\..\include -IC:\Windows\SDL-1.2.14\include\SDL -IC:\Windows\SDL-1.2.14\lib
endif

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
OUTPUT=libGameFramework.a

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@
	
$(OUTPUT): $(OBJECTS) 
	ar rcs $(OUTPUT) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

