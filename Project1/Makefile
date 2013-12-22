CC = g++
CFLAGS = -Wall -Werror
OBJECTS = run.o Stack.o

all: run

Stack.o: Stack.cc Stack.h
	$(CC) $(CFLAGS) -c -o $@ $<

run.o: run.cc run.h Stack.h
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

clean:
	rm -f $(PROGS) *.o *~ run
