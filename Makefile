#
#*Doinakis Michail
#*e-mail: doinakis@ece.auth.gr
#
# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

all:	main_sequential  main_cilk mv.o

main_cilk:	main_cilk.o	rcm_cilk.o	queue.o mmio.o
			gcc-7	-Wall	-fcilkplus	-lcilkrts	-g	rcm_cilk.o	queue.o	main_cilk.o	mmio.o	-o	main_cilk -pg
			
main_cilk.o:	./src/main_cilk.c
			gcc-7	-Wall	-fcilkplus -lcilkrts	-c	 	./src/main_cilk.c -pg

rcm_cilk.o:	./src/rcm_cilk.c
			gcc-7	-Wall	-fcilkplus	-lcilkrts	-c	-g	./src/rcm_cilk.c -pg

main_sequential:	main_sequential.o	rcm.o queue.o mmio.o
			gcc-7	-Wall	-g	rcm.o	queue.o	main_sequential.o mmio.o   	-o	main_sequential  -pg
			
main_sequential.o: ./src/main_sequential.c
			gcc-7	-Wall	-c	-g   	./src/main_sequential.c  -pg

rcm.o: ./src/rcm.c
			gcc-7	-Wall	-c	-g   	./src/rcm.c  -pg

queue.o: ./src/queue.c
			gcc-7	-Wall	-fcilkplus	-lcilkrts	-c	-g   	./src/queue.c  -pg

mmio.o : ./src/mmio.c
			gcc-7	-Wall -fcilkplus	-lcilkrts	-c	-g   	./src/mmio.c  -pg

mv.o:
	mv *.o ./lib
	
clean:
		$(RM)	./lib/*.o main_sequential main_cilk *.csv *.txt *.data  *.out *.o
