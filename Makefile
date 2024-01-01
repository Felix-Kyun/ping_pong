CC = gcc
SRC_DIR = src
BUILD_DIR = $(SRC_DIR)/build
CFLAGS = -lm -lncurses
OUT = ping

_OBJS = paddle.o notify.o ball.o auto.o flib.o
OBJS= $(patsubst %,$(BUILD_DIR)/%,$(_OBJS))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@

# .PHONY: build
build: $(OBJS)
	gcc -o $(OUT) $(SRC_DIR)/$(OUT).c $(OBJS) $(CFLAGS)

run: build
	./$(OUT)

.PHONY: clean
clean: 
	rm -rf $(BUILD_DIR)/* $(OUT)

