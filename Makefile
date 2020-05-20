CC=g++
LIB=lib
BIN=bin
EXE=exec
OBJ=obj
RM=rm
SRC=src
SRCFILES= main.cpp graph.cpp
COMPUTE_LIB=libcompute.a
LIBFLAG=rcs
CFLAGS=-c
USE_LIB=$(var)
INCLUDE=Iinclude



.PHONY:all
all:bin/exec

ifeq ($(USE_LIB),true)
$(BIN)/$(EXE):$(OBJ)/main.o $(LIB)/$(COMPUTE_LIB)
	$(CC) obj/main.o -Llib -lcompute -o $(BIN)/$(EXE)
$(LIB)/$(COMPUTE_LIB): $(OBJ)/graph.o
	ar rcs $(LIB)/$(COMPUTE_LIB)  $(OBJ)/graph.o
else
$(BIN)/$(EXE) : $(OBJ)/main.o $(OBJ)/graph.o
	$(CC) $(OBJ)/graph.o  $(OBJ)/main.o -o $(BIN)/$(EXE)


endif


obj/main.o:src/main.cpp
		g++ -c src/main.cpp -o obj/main.o -Iinclude
obj/graph.o:src/graph.cpp
		g++ -c src/graph.cpp -o obj/graph.o -Iinclude





.PHONY:clean
clean:
	rm -f obj/*.o bin/* lib/*
