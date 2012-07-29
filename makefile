include makefile.inc

all : 
	cd src; $(MAKE)

clean :
	-for d in $(DIRS); do (cd $$d; $(MAKE) clean); done
