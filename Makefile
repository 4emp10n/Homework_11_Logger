CC = g++

SOURCES = main.cpp Logger.cpp

all:
	$(CC) $(SOURCES) -o main

run:
	@./main

clean:
	@rm -rf *.o main