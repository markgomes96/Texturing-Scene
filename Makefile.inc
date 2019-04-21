#These are commands that are needed across all of the Makefiles

# Specify location of SOIL headers and library
OPTHDRSLOC = -I../lib/SOIL
OPTLIBSLOC = -L../lib/SOIL

#Determine the OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	CCFLAGS += -D LINUX
	LBLIBS = -L. -lGLEW -lglut -lGL -lGLU -lm $(OPTLIBSLOC) -lSOIL
endif
ifeq ($(UNAME_S), Darwin)
	CCFLAGS += -D OSX
	LBLIBS = -L. -lGLEW $(OPTLIBSLOC) -lSOIL -framework Carbon -framework OpenGL -framework GLUT
endif

#Set the default compilers.
CC = gcc
C++ = g++

#Note -- if the Portland Group compilers are used then several of the compiler 
# flags will also have to be modified

