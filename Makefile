#Determine the OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	CCFLAGS += -D LINUX
	LBLIBS = -I.usr/include -L/usr/lib64 -lglut -lGL -lGLU -lX11 -lm
endif
ifeq ($(UNAME_S), Darwin)
	CCFLAGS += -D OSX
	LBLIBS = -framework Carbon -framework OpenGL -framework GLUT
endif

CC = gcc
C++ = g++ 
#LIBDIRS = -L/usr/lib64
#INCDIRS = -I/usr/include
#LDLIBS =  -lglut -lGL -lGLU -lX11 -lm

INCLUDES   = includes.h
HEADERS    = structs.h game.h input.h globals.h
OBJS 	   = game.o input.o levelCreate.o defineBox.o drawBox.o physobj.o testobj.o physicsengine.o


CF = -DLEVEL	#-DLEVEL -> to switch to level scene
#DF = -DDEV
all : run

run: main.o $(INCLUDES) $(HEADERS) $(OBJS) 
	$(C++) $(CCFLAGS) $(CF) $(DF) -o run  main.o $(OBJS) $(LBLIBS) #$(INCDIRS) $(LIBDIRS) $(LDLIBS) 

input.o : input.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c input.cc

physobj.o : physobj.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c physobj.cc

testobj.o : testobj.cc $(INCLUDES) $(HEADERS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c testobj.cc

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

main.o : main.cc $(OBJS)
	$(C++) $(CCFLAGS) $(CF) $(DF) -c main.cc 

clean :
	rm *.o

pristine :
	rm *.o
	rm run

purge :
	rm *.o
	rm run
