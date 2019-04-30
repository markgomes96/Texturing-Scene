# Pull in common definitions

include ../Makefile.inc

INCLUDES   = includes.h
HEADERS    = structs.h game.h input.h globals.h prototypes.h menu.h ../lib/SOIL/SOIL.h
OBJS 	   = game.o input.o levelCreate.o defineBox.o drawBox.o physobj.o menu.o \
			 gameobj.o physicsengine.o drawCase.o texturing.o drawHH.o

#Since these compiler flags are specific to the source, leave them in this makefile
#and not in the parent makefile.

CF = -DLEVEL	#-DLEVEL -> to switch to level scene
DF = #-DDEV


all : run tags

run: main.o $(INCLUDES) $(HEADERS) $(OBJS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -o run  main.o $(OPTHDRSLOC) $(OBJS) $(LBLIBS) #$(INCDIRS) $(LIBDIRS) $(LDLIBS)
	mv run ../.

input.o : input.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c input.cc

physobj.o : physobj.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c physobj.cc

gameobj.o : testobj.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c gameobj.cc

physicsengine.o : physicsengine.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c physicsengine.cc

game.o : game.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c game.cc

levelCreate.o : levelCreate.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c levelCreate.cc

defineBox.o : defineBox.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c defineBox.cc

drawBox.o : drawBox.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c drawBox.cc

drawCase.o : drawCase.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) -c drawCase.cc

texturing.o : texturing.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) -c texturing.cc

#objectdata.o : objectdata.cc $(INCLUDES) $(HEADERS)
#	$(C++) $(CCFLAGS) $(CF) -c objectdata.cc

menu.o : menu.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c menu.cc


drawHH.o : drawHH.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) -c drawHH.cc

main.o : main.cc $(OBJS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c main.cc

# make tags for vi

tags :
	ctags *.cc *.h

# make targets to clean up the directory

clean :
	rm *.o

pristine :
	rm *.o
	rm tags
	rm ../run


purge :
	rm *.o
	rm ../run
