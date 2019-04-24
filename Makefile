CC = g++
CFLAGS = -I.

DEPS = Matrix.h

LIBS=-lm


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

test_matrix: test_matrix.o Matrix.o
	$(CC) -o test_matrix test_matrix.o Matrix.o 

clean:
	rm -f *.o test_matrix
