INCLUDE := -I../BST


bst.o:
	g++ -c ../BST/bst.cpp

main.o:
	g++ -c ../main.cpp

all: main.o bst.o
	g++ -o main.exe main.o bst.o $(INCLUDE)

clean:
	del *.exe
	del *.o