CC = g++
CPPFLAGS = -g 

main_DLL2 : main_DLL2.o DLL2.o

main_DLL2.o : DLL2.h main_DLL2.cpp 
DLL2.o : DLL2.h DLL2_node.h DLL2.cpp


clean:
	rm -f core main *.o

