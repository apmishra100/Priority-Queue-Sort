PQueueSort.out : PQueueSort.o 
	g++ -ansi -g -Wall -std=c++11 -o PQueueSort.out PQueueSort.o 

PQueueSort.o : PQueueSort.cpp
	g++ -ansi -g -Wall -std=c++11 -c PQueueSort.cpp

clean :
	rm -f PQueueSort.out PQueueSort.o
