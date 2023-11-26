all: testes main

testes: testes.o newton_gregory.o
	gcc newton_gregory.o testes.o -o testes

main: main.o newton_gregory.o
	gcc newton_gregory.o main.o -o main

testes.o: testes.c newton_gregory.h
	gcc -c testes.c

main.o: main.c newton_gregory.h
	gcc -c main.c

newton_gregory.o: newton_gregory.c newton_gregory.h
	gcc -c newton_gregory.c
