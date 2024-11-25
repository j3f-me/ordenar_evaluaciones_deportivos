CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Iinclude
LDFLAGS = -lrt -lm
BUILD_DIR = build
ARGS = 'datos_desordenados.txt' -v

SRCS = src/main.c src/lector.c src/utils.c  src/atleta.c src/ordenamiento.c
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
	rm -f "evaluaciones_ordenadas.txt"
	rm -f "reporte.txt"


run: $(TARGET)
		./$(TARGET) $(ARGS)
