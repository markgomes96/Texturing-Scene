CC = gcc
C++ = g++ 
LIBDIRS = -L/usr/lib64
INCDIRS = -I/usr/include
LDLIBS =  -lglut -lGL -lGLU -lX11 -lm

INCLUDES   = includes.h
HEADERS    = structs.h game.h input.h globals.h
OBJS 	   = game.o input.o levelCreate.o defineBox.o drawBox.o physobj.o testobj.o physicsengine.o

all : run

run: main.o $(INCLUDES) $(HEADERS) $(OBJS) 
	$(C++) -o run main.o $(OBJS) $(INCDIRS) $(LIBDIRS) $(LDLIBS) 

input.o : input.cc $(INCLUDES) $(HEADERS)
	$(C++) -c input.cc

physobj.o : physobj.cc $(INCLUDES) $(HEADERS)
	$(C++) -c physobj.cc

testobj.o : testobj.cc $(INCLUDES) $(HEADERS)
	$(C++) -c testobj.cc

physicsengine.o : physicsengine.cc $(INCLUDES) $(HEADERS)
	$(C++) -c physicsengine.cc

game.o : game.cc $(INCLUDES) $(HEADERS)
	$(C++) -c game.cc

levelCreate.o : levelCreate.cc $(INCLUDES) $(HEADERS)
	$(C++) -c levelCreate.cc

defineBox.o : defineBox.cc $(INCLUDES) $(HEADERS)
	$(C++) -c defineBox.cc

drawBox.o : drawBox.cc $(INCLUDES) $(HEADERS)
	$(C++) -c drawBox.cc

main.o : main.cc $(OBJS)
	$(C++) -c main.cc 

clean :
	rm *.o

pristine :
	rm *.o
	rm run
