# IDIR =../include
IDIR = ./src
CC=gcc
# CFLAGS=-I$(IDIR)
CFLAGS=

ODIR=obj

LIBS=-lncurses

_DEPS = ping.h ball.h notify.h paddle.h setting.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ =  ping.o ball.o notify.o paddle.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

