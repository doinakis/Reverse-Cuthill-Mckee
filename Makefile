#
#*Doinakis Michail
#*e-mail: doinakis@ece.auth.gr
#
# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects
all:	main_sequential main_cilk mv.o

main_cilk:	main_cilk.o	rcm_cilk.o	queue.o
			gcc-7	-fcilkplus	-lcilkrts	-O3	rcm_cilk.o	queue.o	main_cilk.o	-o	main_cilk
			
main_cilk.o:	./src/main_cilk.c
			gcc-7	-fcilkplus -lcilkrts	-c	-O3	./src/main_cilk.c

rcm_cilk.o:	./src/rcm_cilk.c
			gcc-7	-fcilkplus	-lcilkrts	-c	-O3	./src/rcm_cilk.c

main_sequential:	main_sequential.o	rcm.o queue.o
			gcc-7	-O3	rcm.o	queue.o	main_sequential.o	-o	main_sequential
			
main_sequential.o: ./src/main_sequential.c
			gcc-7	-c	-O3	./src/main_sequential.c

rcm.o: ./src/rcm.c
			gcc-7	-c	-O3	./src/rcm.c
queue.o: ./src/queue.c
			gcc-7	-fcilkplus	-lcilkrts	-c	-O3	./src/queue.c

example: example.o
			g++	-o3	-g example.o -o example
			
example.o: example.cpp
			g++ -c -g example.cpp

mv.o:
	mv *.o ./lib
clean:
		$(RM)	./lib/*.o main_sequential main_cilk *.csv *.txt *.data example *.out
