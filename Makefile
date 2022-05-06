all: main.c DDetect.o
	gcc -Wall -o Deadlock main.c DDetect.o

DDetect.o: DDetect.h DDetect.c
	gcc -Wall -c DDetect.c

clean:
	rm -f Deadlock *.o
