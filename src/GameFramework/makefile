CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lSDLmain -lSDL -lGL -lSDL_image
INCLUDES=-I../../include/GameFramework/
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=framework

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(INCLUDES) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
