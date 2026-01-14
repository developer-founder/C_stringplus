CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

SRC_DIR = s21_string_functions
SRC = $(SRC_DIR)/*.c
OBJ = $(SRC:.c=.o)

TSRC_DIR = tests
TSRC = $(TSRC_DIR)/*.c
TOBJ = $(TSRC:.c=.o)

AR = ar
ARFLAGS = rcs

LIB_NAME = s21_string.a
NAME = s21_string

SRC_DIR = s21_string_functions
SRC = $(SRC_DIR)/*.c
OBJ = $(SRC:.c=.o)

TSRC_DIR = tests
TSRC = $(TSRC_DIR)/*.c
TOBJ = $(TSRC:.c=.o)

.PHONY: all clean test gcov_report

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^
	mv *.o s21_string_functions

$(TOBJ): $(TSRC)
	$(CC) $(CFLAGS) -c $^
	mv *.o tests

all: test

test: $(OBJ) $(TOBJ)
	$(CC) $^ $(CFLAGS) -o $(NAME) $(LIBS)
	rm -rf *.o *.a $(SRC_DIR)/*.o $(TSRC_DIR)/*.o
	./$(NAME)

check_style:
	clang-format -n --style="Google" $(SRC_DIR)/*.c $(SRC_DIR)/*.h $(TSRC_DIR)/*.c $(TSRC_DIR)/*.h

fix_style:
	clang-format -i --style="Google" $(SRC_DIR)/*.c $(TSRC_DIR)/*.c $(TSRC_DIR)/*.h

clean:
	rm -rf *.o *.a $(SRC_DIR)/*.o $(TSRC_DIR)/*.o