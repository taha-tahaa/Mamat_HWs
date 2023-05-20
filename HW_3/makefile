# Welcomre to Mamat, 044101
#
# This is the project's Makefile. It contains the instructions for compiling
# the projects C files, and then link the generated objects into an executable.
# This simple file will compile "main.c" to "main.o" and then link it (with C
# runtime library) to the executable "prog.exe".
#
# To compile, open the terminal in the folder that contains
# this file and run "make".
#
# To clean, open the terminal in the folder that contains
# this file and run "make clean".
#
# All eclipse projects in this machine are under /home/mamat/Documents/
# Compiler
CC = gcc

# Linker
CCLINK = $(CC)

# Compiler flags
CFLAGS = -g -Wall -std=c99

# Object files
OBJS = main.o stack.o student.o

# The first rule is invoked by default
prog.exe: $(OBJS)
	$(CCLINK) $(OBJS) -o prog.exe

# Compilation rules
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

student.o: student.c student.h stack.h
	$(CC) $(CFLAGS) -c student.c

main.o: main.c stack.h student.h
	$(CC) $(CFLAGS) -c main.c

# Clean rule
clean:
	rm -rf *.o *.exe
