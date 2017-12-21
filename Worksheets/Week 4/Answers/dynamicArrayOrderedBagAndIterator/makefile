all: prog

prog: dynamicArray.o main.o
	gcc -g -Wall -std=c99 -o prog dynamicArray.o main.o
	
main.o: main.c dynamicArray.h
	gcc -g -Wall -std=c99 -c main.c
	
dynamicArray.o: dynamicArray.c dynamicArray.h
	gcc -g -Wall -std=c99 -c dynamicArray.c

clean:	
	rm dynamicArray.o
	rm main.o
	rm prog
