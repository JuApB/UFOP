all: pratica.o aluno.o
	@gcc pratica.o aluno.o -o exe -lm
	@rm -r pratica.o aluno.o
aluno.o: aluno.c
	@gcc aluno.c -c -Wall
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
run:
	@./exe
