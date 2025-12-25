SRC = s21_string_functions/s21_memchr.c s21_string_functions/s21_memcmp.c s21_string_functions/s21_strncmp.c s21_string_functions/s21_memcpy.c
TARGET = s21_stringplus

.PHONY: all clean test gcov_report run

all: run

run:
	gcc -c $(SRC)
	ar r s21_stringlib.a *.o
	gcc test_library.c -L. s21_stringlib.a
	rm -rf *.o
	./a.out

clean:
	rm -rf *.a
	rm -rf *.o