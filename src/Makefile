SRC = s21_memchr.c
TARGET = s21_stringplus

.PHONY: all clean test gcov_report run

all: run

run:
	gcc -c s21_memchr.c
	ar r s21_stringlib.a *.o
	gcc test_library.c -L. s21_stringlib.a
	./a.out

clean:
	rm -rf *.a
	rm -rf *.o