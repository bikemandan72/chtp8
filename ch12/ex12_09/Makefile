CC = gcc
CFLAGS = -Wall -lm -g
#export CFLAGS
SRCS = $(wildcard *.c)
LIB = ../lib/list.c

.PHONY: all clean

all: $(SRCS:.c=)

clean:
	rm -rf $(SRCS:.c=) $(LIB:.c=.o)

$(SRCS:.c=): $(SRCS) $(LIB:.c=.o) $(LIB:.c=.h)
	$(CC) $^ -o $@ $(CFLAGS)