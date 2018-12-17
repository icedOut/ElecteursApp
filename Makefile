# Makefile pour INF3105 / TP3

#OPTIONS = -Wall           # option standard
#OPTIONS = -g -O0 -Wall    # pour rouler dans gdb
OPTIONS = -O2 -Wall        # pour optimiser

#
all : tp3a tp3b

tp3a : tp3a.cpp carte.h carte.o fcarte.o pointst.h pointst.o
	g++ ${OPTIONS} -o tp3a tp3a.cpp pointst.o carte.o fcarte.o

tp3b : tp3b.cpp carte.o fcarte.o pointst.o 
	g++ ${OPTIONS} -o tp3b tp3b.cpp carte.o fcarte.o pointst.o

carte.o : carte.cpp carte.h pointst.h
	g++ ${OPTIONS} -c -o carte.o carte.cpp

fcarte.o : fcarte.cpp carte.h
	g++ ${OPTIONS} -c -o fcarte.o fcarte.cpp

pointst.o : pointst.cpp pointst.h
	g++ ${OPTIONS} -c -o pointst.o pointst.cpp

clean:
	rm -rf tp3[ab] *~ *.o

