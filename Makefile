#
#*Doinakis Michail
#*e-mail: doinakis@ece.auth.gr
#
# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects
all:	main

main: main.o rcm.o queue.o
			gcc-7 -fcilkplus -lcilkrts -o3 -g rcm.o queue.o main.o -o main
main.o: main.c
			gcc-7 -fcilkplus -lcilkrts -c	-g main.c
rcm.o: rcm.c
			gcc-7 -fcilkplus -lcilkrts -c	-g rcm.c
queue.o: queue.c
			gcc-7 -fcilkplus -lcilkrts -c	-g queue.c
example: example.o
			g++ -o3 -g example.o -o example
example.o: example.cpp
			g++ -c -g example.cpp
clean:
		$(RM)	*.o main *.csv *.txt *.data example
