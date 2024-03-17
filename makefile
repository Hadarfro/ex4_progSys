CC = gcc
AR = ar
CFLAGS = -Wall -g

all: digitcompress

libCompress.a: compress.o
	$(AR) rcs libCompress.a compress.o

compress.o: compress.c compress.h
	$(CC) $(CFLAGS) -c compress.c

digitcompress: encodemain.o 
	$(CC) $(CFLAGS) $^ -o $@

encodemain.o: encodemain.c compress.h
	$(CC) $(CFLAGS) -c encodemain.c


.PHONY: clean all

clean:
	rm -f *.o *.a digitcompress