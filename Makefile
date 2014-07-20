zlmaker: main.o genorate.o
	gcc -g main.o genorate.o -o zlmaker
main.o:main.c genorate.h
	gcc -g -c main.c genorate.h;
genorate.o: genorate.c genorate.h
	gcc -g -c genorate.c genorate.h

clean:
	rm -f zlmaker
	rm -f *.o
