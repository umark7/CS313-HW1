CC = g++
CPPFLAGS = -g 

main_DLL1 : main_DLL1.o DLL1.o

main_DLL1.o : DLL1.h main_DLL1.cpp 
DLL1.o : DLL1.h DLL1_node.h DLL1.cpp


clean:
	rm -f core main *.o

