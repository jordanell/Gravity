include ../makefile.inc

UNAME:= $(shell uname)
ifeq ($(UNAME), Linux)
LDFLAGS=-lSDLmain -lSDL -lGL -lSDL_image -lSDL_ttf
else ifeq ($(UNAME), Darwin)
LDFLAGS=-framework OpenGL -framework SDL -framework SDL_image -framework cocoa -lSDLmain -lSDL_ttf
else
LDFLAGS=-LC:\Windows\SDL-1.2.14\lib -lmingw32 -lSDLmain -lSDL -lopengl32 -lglu32 -lSDL_image
endif

ifeq ($(UNAME), Linux)
INCLUDES=-I../include/framework/ -I../include/ -I../include/scene/ -I../include/gui/ -I../include/map/
else ifeq ($(UNAME), Darwin)
INCLUDES=-I../include/framework/ -I../include/ -F/Library/Frameworks/ -I/Library/Frameworks/SDL.framework/Headers -I/Library/Frameworks/SDL_image.framework/Headers -I/Library/Frameworks/SDL_ttf.framework/Headers
else
INCLUDES=-I.\..\include\framework -I.\..\include -IC:\Windows\SDL-1.2.14\include\SDL -IC:\Windows\SDL-1.2.14\lib
endif

SOURCES	= $(wildcard *.cpp)
OBJECTS	= $(SOURCES:.cpp=.o)
OBJLIBS = libframework.a libmap.a libgui.a libscene.a
LIBS	= -lscene -lmap -lgui -lframework -L.
DIRS	= framework gui scene map

EXECUTABLE=Game

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) $(OBJLIBS)
	$(CC) $(INCLUDES) $(OBJECTS) -o ../bin/$@ $(LIBS) $(LDFLAGS)

libframework.a : force_look
	cd framework; $(MAKE)

libgui.a : force_look
	cd gui; $(MAKE)
	
libscene.a : force_look
	cd scene; $(MAKE)
	
libmap.a : force_look
	cd map; $(MAKE)

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
	-for d in $(DIRS); do (cd $$d; $(MAKE) clean ); done

force_look :
	true

