CC = gcc
C++ = g++ 
LIBDIRS = -L/usr/lib64
INCDIRS = -I/usr/include
LDLIBS =  -lglut -lGL -lGLU -lX11 -lm

INCLUDES   = includes.h
HEADERS    = structs.h game.h input.h
OBJS 	   = game.o input.o

all : run

run: main.o $(INCLUDES) $(HEADERS) $(OBJS) 
	$(C++) -o run main.o $(OBJS) $(INCDIRS) $(LIBDIRS) $(LDLIBS) 

input.o : input.cc $(INCLUDES) $(HEADERS)
	$(C++) -c input.cc

game.o : game.cc $(INCLUDES) $(HEADERS)
	$(C++) -c game.cc

main.o : main.cc
	$(C++) -c main.cc 

clean :
	rm *.o

pristine :
	rm *.o
	rm run
