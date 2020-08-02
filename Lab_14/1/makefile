cycle: cycle_main.o cycle.o
	gcc cycle_main.o cycle.o -o output

lista_main.o: cycle_main.c
	gcc -o cycle_main.c -Wall

lista.o: cycle.c cycle.h
	gcc -c cycle.c -Wall

clean:
	rm *.o cycle
