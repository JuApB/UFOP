all: pratica.o heap.o
	@gcc pratica.o heap.o -o exe
	@rm -r *.o
pratica.o: pratica.c
	@gcc pratica.c -c
heap.o: heap.c
	@gcc heap.c -c
run:
	@./exe
