CC = g++
CFLAGS = -std=c++11 -Wall
RM = rm

all: 
	$(CC) -o parkinglot $(CFLAGS) main.cpp

clean:
	$(RM) parkinglot
