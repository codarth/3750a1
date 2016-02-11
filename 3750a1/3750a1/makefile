OBJS = main.o astar.o node.o
SRCS = main.cpp astar.cpp node.cpp
CC = g++11
CFLAGS = -Wall -g -std=c++11 -lcppunit -ldl

all: astar

astar: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lcppunit -ldl

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *~ *% *# .#*


clean-all:
	rm -f *.o *~ *% *# .#*
	rm astar