CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -I/opt/homebrew/Cellar/check/0.15.2/include
LDFLAGS = -L/opt/homebrew/Cellar/check/0.15.2/lib
LIBS = -lcheck -lm -lpthread

SRC_DIR = s21_string_functions
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

TSRC_DIR = tests
TSRC = $(wildcard $(TSRC_DIR)/*.c)
TOBJ = $(TSRC:.c=.o)

TEST = test_s21_string

AR = ar
ARFLAGS = rcs

LIB_NAME = s21_string.a

.PHONY: all clean test check_style fix_style

all: test

$(LIB_NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TOBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) $(TOBJ) $(LIB_NAME) $(LDFLAGS) -o $(TEST) $(LIBS)
	./$(TEST)
	rm -rf $(OBJ) $(TOBJ)

check_style:
	clang-format -n --style="Google" $(SRC_DIR)/*.c $(SRC_DIR)/*.h $(TSRC_DIR)/*.c $(TSRC_DIR)/*.h

fix_style:
	clang-format -i --style="Google" $(SRC_DIR)/*.c $(SRC_DIR)/*.h $(TSRC_DIR)/*.c $(TSRC_DIR)/*.h

clean:
	rm -rf $(OBJ) $(TOBJ) $(TEST)