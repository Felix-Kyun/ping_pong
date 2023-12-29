CC = gcc
IDIR = ./src
_DEPS = paddle.c notify.c ball.c auto.c flib.c
CFLAGS = -lm -lncurses

# conversions
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

run:
	$(CC) src/ping.c $(DEPS) -o ping_pong $(CFLAGS)
	./ping_pong

