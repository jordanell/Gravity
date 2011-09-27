CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lSDLmain -lSDL -lGL -lSDL_image -L./GameFramework -lGameFramework
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
