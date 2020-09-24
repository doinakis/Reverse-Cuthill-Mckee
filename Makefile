#
#*Doinakis Michail
#*e-mail: doinakis@ece.auth.gr
#
# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

all:	main_sequential  main_cilk  mv.o

main_cilk:	main_cilk.o	rcm_cilk.o	queue.o mmio.o
			gcc-7	-Wall	-O3	-fcilkplus	-lcilkrts	rcm_cilk.o	queue.o	main_cilk.o	mmio.o	-o	main_cilk 
			
main_cilk.o:	./src/main_cilk.c
			gcc-7	-Wall	-O3	-fcilkplus	-lcilkrts	-c	./src/main_cilk.c 

rcm_cilk.o:	./src/rcm_cilk.c
			gcc-7	-Wall	-O3	-fcilkplus	-lcilkrts	-c	./src/rcm_cilk.c 

main_sequential:	main_sequential.o	rcm.o	queue.o	mmio.o
			gcc-7	-Wall	-O3	rcm.o	queue.o	main_sequential.o	mmio.o	-o	main_sequential  
			
main_sequential.o: ./src/main_sequential.c
			gcc-7	-Wall	-O3	-c	./src/main_sequential.c  

rcm.o: ./src/rcm.c
			gcc-7	-Wall	-O3	-c	./src/rcm.c  

queue.o: ./src/queue.c
			gcc-7	-Wall	-O3	-fcilkplus	-fopenmp	-lcilkrts	-c	./src/queue.c  

mmio.o : ./src/mmio.c
			gcc-7	-Wall	-O3	-fcilkplus	-fopenmp	-lcilkrts	-c	./src/mmio.c  

mv.o:
	mv	*.o	./lib
	
clean:
		$(RM)	./lib/*.o main_sequential main_cilk main_openmp *.csv  *.data  *.out *.o
