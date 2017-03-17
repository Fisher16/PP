CC = gcc
LIBS = `allegro-config --libs`
CFLAGS = -Wall -pedantic -O2 -std=c99 -fgnu89-inline
program08: main.o grafika.o
		$(CC) -o program08 main.o grafika.o $(CFLAGS) $(LIBS)
main.o:	main.c grafika.h
		$(CC) -o main.o -c main.c $(CFLAGS)
grafika.o:	grafika.c grafika.h
		$(CC) -o grafika.o -c grafika.c $(CFLAGS)
clean:
		rm *.o
