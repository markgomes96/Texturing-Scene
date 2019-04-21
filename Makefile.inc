#These are commands that are needed across all of the Makefiles

#Determine the OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	CCFLAGS += -D LINUX
	LBLIBS = -L. -lSOIL -lGLEW -lglut -lGL -lGLU -lm
endif
ifeq ($(UNAME_S), Darwin)
	CCFLAGS += -D OSX
	LBLIBS = -L. -lSOIL -lGLEW -framework Carbon -framework OpenGL -framework GLUT
endif


CC = gcc
C++ = g++
#LIBDIRS = -L/usr/lib64
#INCDIRS = -I/usr/include
#LDLIBS =  -lglut -lGL -lGLU  -lX11 -lm
