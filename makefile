CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -pedantic-errors -std=c11
LINK    = $(CC) $(CFLAGS)
COMPILE = $(CC) $(CFLAGS) -c
INCLUDE = -I ./include/
EXE		= a.out
DEPS    = ./main.c

$(EXE) : $(DEPS)
	$(LINK) $(DEPS) -o $(EXE)
