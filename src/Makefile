SRC = s21_string_functions/s21_memset.c s21_string_functions/s21_memchr.c s21_string_functions/s21_memcmp.c s21_string_functions/s21_strncmp.c s21_string_functions/s21_memcpy.c s21_string_functions/s21_strlen.c
TARGET = s21_stringplus

.PHONY: all clean test gcov_report run

all: run

run:
	gcc -c $(SRC)
	ar r s21_stringlib.a *.o
	gcc tests/s21_test_strlen.c -L. s21_stringlib.a -o s21_test.out
	rm -rf *.o
	./s21_test.out

clean:
	rm -rf *.a
	rm -rf *.o