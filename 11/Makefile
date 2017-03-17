CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic
LIBS=`allegro-config --libs`

program11:	main.o arg.o io.o sygnal.o grafika.o
		$(CXX) -o program11 main.o arg.o io.o sygnal.o grafika.o $(CXXFLAGS) $(LIBS)
main.o:	main.cpp 
		$(CXX) -o main.o -c main.cpp $(CXXFLAGS)
arg.o:	arg.cpp
		$(CXX) -o arg.o -c arg.cpp $(CXXFLAGS)
io.o:	io.cpp
		$(CXX) -o io.o -c io.cpp $(CXXFLAGS)
sygnal.o:	sygnal.cpp
		$(CXX) -o sygnal.o -c sygnal.cpp $(CXXFLAGS)
grafika.o:	grafika.cpp
		$(CXX) -o grafika.o -c grafika.cpp $(CXXFLAGS)

clean:
		rm *.o
