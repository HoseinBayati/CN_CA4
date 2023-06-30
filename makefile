all: tcpSim.out

tcpSim.out: main.o RenoTCPConnection.o NewRenoTCPConnection.o BBRTCPConnection.o
	g++  main.o RenoTCPConnection.o NewRenoTCPConnection.o BBRTCPConnection.o -o tcpSim.out

main.o: main.cpp RenoTCPConnection.hpp
	g++ -c main.cpp -o main.o

RenoTCPConnection.o: RenoTCPConnection.cpp RenoTCPConnection.hpp constants.hpp
	g++ -c RenoTCPConnection.cpp -o RenoTCPConnection.o


NewRenoTCPConnection.o: NewRenoTCPConnection.cpp NewRenoTCPConnection.hpp constants.hpp
	g++ -c NewRenoTCPConnection.cpp -o NewRenoTCPConnection.o


BBRTCPConnection.o: BBRTCPConnection.cpp BBRTCPConnection.hpp constants.hpp
	g++ -c BBRTCPConnection.cpp -o BBRTCPConnection.o

clean:
	rm -r -f *.out
	rm -r -f *.o