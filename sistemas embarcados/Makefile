all: testes main

testes: testes.o newtonGregory.o
	gcc newtonGregory.o testes.o -o testes

main: main.o newtonGregory.o
	gcc newtonGregory.o main.o -o main

testes.o: testes.c newtonGregory.h
	gcc -c testes.c

main.o: main.c newtonGregory.h
	gcc -c main.c

newtonGregory.o: newtonGregory.c newtonGregory.h
	gcc -c newtonGregory.c
