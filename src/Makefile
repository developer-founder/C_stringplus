CC = gcc
LDFLAGS = -L/opt/homebrew/Cellar/check/0.15.2/lib
CFLAGS      = -Wall -Werror -Wextra -std=c11 -I/opt/homebrew/Cellar/check/0.15.2/include
TEST_CFLAGS = -Wall -Wextra -std=c11 -I/opt/homebrew/Cellar/check/0.15.2/include
SRC=s21_string_functions/*.c
OBJ=$(SRC:.c=.o)
TSRC=tests/*.c
TOBJ=$(TSRC:.c=.o)
LIB_NAME=s21_string.a
NAME=s21_string
UNAME=$(shell uname -s)

ifeq ($(UNAME), Linux)
	LIBS=-lcheck -lm -lrt -lpthread -lsubunit
endif
ifeq ($(UNAME), Darwin)
	LIBS=-lcheck
endif

GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CHECK_FLAGS = $(LIBS)

all: clean $(LIB_NAME) test gcov_report

clean:
	rm -rf $(OBJ) $(TOBJ) s21_string report coverage.info *.o *.gcda *.gcno s21_tests $(LIB_NAME)

test: $(OBJ) $(TOBJ)
	$(CC) $^ $(CFLAGS) -o $(NAME) $(LIBS)
	./$(NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^
	mv *.o s21_string_functions

$(TOBJ): $(TSRC)
	$(CC) $(CFLAGS) -c $^
	mv *.o tests

rebuild: clean $(LIB_NAME) test

check_style:
	clang-format -n --style="Google" s21_string_functions/*.c s21_string_functions/*.h tests/*.c *.h

fix_style:
	clang-format -i --style="Google" s21_string_functions/*.c s21_string_functions/*.h tests/*.c *.h

gcov_report:
	$(CC) $(TEST_CFLAGS) $(GCOV_FLAGS) $(SRC) $(TSRC) -o s21_test_gcov $(LDFLAGS) $(LIBS) -lm
	./s21_test_gcov
	lcov --capture --directory . --output-file coverage.info --no-external
	genhtml coverage.info --output-directory report
	open report/index.html
	rm -rf *.gcda *.gcno *.info s21_test_gcov