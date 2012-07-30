include ../../makefile.inc

UNAME:= $(shell uname)
ifeq ($(UNAME), Linux)
INCLUDES=-I../../include/framework/ -I../../include/gui/ -I../../include/
endif

SOURCES	= $(wildcard *.cpp)
OBJECTS	= $(SOURCES:.cpp=.o)
OBJLIBS	= ../libgui.a

all : $(OBJLIBS)

../libgui.a : $(OBJECTS)
	$(AR) $(ARFLAGS) ../libgui.a $?
	ranlib ../libgui.a

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

