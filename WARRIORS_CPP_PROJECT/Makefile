CFLAGS = -O
CC = g++

all: Run

Run: Run.cpp Warriors.cpp Battle.cpp
	$(CC) -o Run Run.o Warriors.o Battle.o -lm

Run.o: Run.cpp
	$(CC) $(CFLAGS) -c Run.cpp

Warriors.o: Warriors.cpp
	$(CC) $(CFLAGS) -c Warriors.cpp

Battle.o: Battle.cpp
	$(CC) $(CFLAGS) -c Battle.cpp

clean:
	rm -f core *.o 