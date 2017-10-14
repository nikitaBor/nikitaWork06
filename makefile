all: llist.o main.o
	gcc main.o llist.o -o llist_test

main.o: main.c llist.h
	gcc -c main.c

llist.o: llist.c llist.h
	gcc -c llist.c

clean:
	rm *.o

run: all
	./llist_test
