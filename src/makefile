CC=g++
CFLAGS=-c -Wall

UNAME:= $(shell uname)
ifeq ($(UNAME), Linux)
LDFLAGS=-lSDLmain -lSDL -lGL -lSDL_image -L./GameFramework -lGameFramework
endif
ifeq ($(UNAME), Darwin)
LDFLAGS=`sdl-config -libs -cflags` -L./GameFramework -lGameFramework -framework Cocoa
endif

INCLUDES=-I../include/GameFramework/ -I../include/
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
