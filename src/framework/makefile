include ../../makefile.inc

UNAME:= $(shell uname)
ifeq ($(UNAME), Linux)
INCLUDES=-I../../include/framework/ -I../../include/
else ifeq ($(UNAME), Darwin)
INCLUDES=-I../../include/framework/ -I../../include/ -F/Library/Frameworks/ -I/Library/Frameworks/SDL.framework/Headers -I/Library/Frameworks/SDL_image.framework/Headers
else
INCLUDES=-I.\..\..\include\framework -I.\..\..\include -IC:\Windows\SDL-1.2.14\include\SDL -IC:\Windows\SDL-1.2.14\lib
endif

SOURCES	= $(wildcard *.cpp)
OBJECTS	= $(SOURCES:.cpp=.o)
OBJLIBS	= ../libframework.a

all : $(OBJLIBS)

../libframework.a : $(OBJECTS)
	$(AR) $(ARFLAGS) ../libframework.a $?
	ranlib ../libframework.a

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

