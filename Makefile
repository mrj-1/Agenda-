main.o: main.c
	gcc main.c -c

agenda.o: agenda.c
	gcc agenda.c -c

a.out: main.o agenda.o
	gcc main.o agenda.o

run: a.out
	./a.out

clean: 
	rm -f a.out main.o agenda.o
