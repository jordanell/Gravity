CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lSDLmain -lSDL -lGL -lSDL_image
INCLUDES=-I../../include/GameFramework/
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
OUTPUT=libGameFramework.a

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@
	
$(OUTPUT): $(OBJECTS) 
	ar rcs $(OUTPUT) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
