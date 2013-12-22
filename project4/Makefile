CC = g++
CFLAGS = -Wall -Werror -pedantic
OBJECTS = run.o

all: run

run.o: run.cc convolution.h convolution.cc
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

clean:
	rm -f $(PROGS) *.o *~ run
