include ../../makefile.inc

UNAME:= $(shell uname)
ifeq ($(UNAME), Linux)
INCLUDES=-I../../include/framework/ -I../../include/gui/ -I../../include/scene/ -I../../include/ -I../../include/map/ -I../../include/entities/
endif

SOURCES	= $(wildcard *.cpp)
OBJECTS	= $(SOURCES:.cpp=.o)
OBJLIBS	= ../libentities.a

all : $(OBJLIBS)

../libentities.a : $(OBJECTS)
	$(AR) $(ARFLAGS) ../libentities.a $?
	ranlib ../libentities.a

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

