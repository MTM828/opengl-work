SRC_DIR ?= src/
INC_DIR ?= src/
OBJ_DIR ?= tmp/
BIN_DIR ?= bin/

EXEC_NAME ?= gl
TARGET_EXEC ?= $(BIN_DIR)$(EXEC_NAME)

CFLAGS = -c -g -I$(INC_DIR) -I$(SRC_DIR) -I/usr/local/include -Wall -O0

LDLIBS = -lGLEW -lglfw -lGLU -lGL
LDFLAGS = -o$(TARGET_EXEC) -g -L/usr/local/lib

LDFLAGS += $(LDLIBS)

default:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)
	$(CC) $(SRC_DIR)main.c $(CFLAGS) -o $(OBJ_DIR)main.o
	$(CC) $(SRC_DIR)util.c $(CFLAGS) -o $(OBJ_DIR)util.o
	$(CC) $(SRC_DIR)gutil.c $(CFLAGS) -o $(OBJ_DIR)gutil.o
	$(CC) $(SRC_DIR)context.c $(CFLAGS) -o $(OBJ_DIR)context.o
	$(CC) $(OBJ_DIR)*.o $(LDFLAGS) -o $(TARGET_EXEC)

install:
	cp $(TARGET_EXEC) $(PREFIX)$(EXEC_NAME)

uninstall:
	rm $(PREFIX)$(EXEC_NAME)

clean:
	rm $(OBJ_DIR)*.o
