all: tcpSim.out

tcpSim.out: main.o TCPConnection.o
	g++  main.o TCPConnection.o -o tcpSim.out

main.o: main.cpp TCPConnection.hpp
	g++ -c main.cpp -o main.o

TCPConnection.o: TCPConnection.cpp TCPConnection.hpp 
	g++ -c TCPConnection.cpp -o TCPConnection.o

clean:
	rm -r -f *.out
	rm -r -f *.o