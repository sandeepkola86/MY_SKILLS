prg.out: main.o add.o sub.o mul.o
	gcc -o prg.out main.o add.o sub.o mul.o
main.o: main.c
	gcc -c main.c
add.o: add.c
	gcc -c add.c
sub.o: sub.c
	gcc -c sub.c
mul.o: mul.c
	gcc -c mul.c
clear:
	rm *.o*.out

