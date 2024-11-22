CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Iinclude
LDFLAGS = -lm
BUILD_DIR = build
ARGS = 'datos_desordenados.txt'

SRCS = src/lector.c src/main.c src/utils.c  src/atleta.c
OBJS = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRCS))

TARGET = $(BUILD_DIR)/ordenar_eval

all: $(TARGET)

# build rules for TARGET
$(TARGET): $(BUILD_DIR) $(OBJS)
		$(CC) $(OBJS) -o $@ $(LDFLAGS)

# rule for build dir
$(BUILD_DIR):
		mkdir -p $(BUILD_DIR)

#rule for objects
$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)


run: $(TARGET)
		./$(TARGET) $(ARGS)
