include ../../makefile.inc

UNAME:= $(shell uname)
ifeq ($(UNAME), Linux)
INCLUDES=-I../../include/framework/ -I../../include/gui/ -I../../include/scene/ -I../../include/ -I../../include/map/
endif

SOURCES	= $(wildcard *.cpp)
OBJECTS	= $(SOURCES:.cpp=.o)
OBJLIBS	= ../libscene.a

all : $(OBJLIBS)

../libscene.a : $(OBJECTS)
	$(AR) $(ARFLAGS) ../libscene.a $?
	ranlib ../libscene.a

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

