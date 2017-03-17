CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic 
LIBS=

program11:	main.o arg.o io.o
		$(CXX) -o program11 main.o arg.o io.o $(CXXFLAGS) $(LIBS)
main.o:	main.cpp
		$(CXX) -o main.o -c main.cpp $(CXXFLAGS)
arg.o:	arg.cpp
		$(CXX) -o arg.o -c arg.cpp $(CXXFLAGS)
io.o:	io.cpp
		$(CXX) -o io.o -c io.cpp $(CXXFLAGS)
clean:
		rm *.o
