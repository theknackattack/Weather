CCFLAGS = gcc --std=c2x -Wall -Werror -Wimplicit
HEADERS = Header/Severe.h Header/Syntax.h Header/Winter.h
PROGRAM = main

OBJDIRE := Object
SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c, $(OBJDIRE)/%.o, $(SOURCES))

$(OBJDIRE)/%.o: %.c $(HEADERS)
				mkdir -p $(OBJDIRE)
				$(CCFLAGS) -c $< -o $@

.PHONY: 		all clean

all: 			$(PROGRAM)

$(PROGRAM):		$(OBJECTS) 
				$(CCFLAGS) -o $@ $^
%.o:			%.c $(HEADERS)
				$(CCFLAGS) -c $<
clean:
				rm -r Object
				rm $(PROGRAM)