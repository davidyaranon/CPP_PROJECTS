CFLAGS = -Wall -g
CC = g++

Run: Run.o Warriors.o Battle.o
	$(CC) $(CFLAGS) -o Run Run.o Warriors.o Battle.o

Run.o: Run.cpp Warriors.hpp Battle.hpp
	$(CC) $(CFLAGS) -c Run.cpp

Warriors.o: Warriors.hpp

Battle.o: Battle.hpp Warriors.hpp

clean:
	rm -f core *.o
