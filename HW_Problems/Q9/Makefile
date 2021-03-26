CC = g++
CPPFLAGS = -g 

deBruijn : deBruijn.o LL_Type.o 

deBruijn.o : LL_Type.h deBruijn.cpp 
LL_Type.o : LL_Type.h node.h LL_Iterator


clean:
	rm -f core main *.o
