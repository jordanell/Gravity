include ../../makefile.inc

UNAME:= $(shell uname)
ifeq ($(UNAME), Linux)
INCLUDES=-I../../include/framework/ -I../../include/gui/ -I../../include/scene/ -I../../include/ -I../../include/map/
endif

SOURCES	= $(wildcard *.cpp)
OBJECTS	= $(SOURCES:.cpp=.o)
OBJLIBS	= ../libmap.a

all : $(OBJLIBS)

../libmap.a : $(OBJECTS)
	$(AR) $(ARFLAGS) ../libmap.a $?
	ranlib ../libmap.a

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

