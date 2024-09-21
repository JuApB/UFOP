all: pratica.o hash.o
	@gcc pratica.o hash.o -o exe -lm
	@rm -r pratica.o
	@rm -r hash.o
hash.o: hash.c
	@gcc hash.c -c -Wall
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
run:
	@./exe
