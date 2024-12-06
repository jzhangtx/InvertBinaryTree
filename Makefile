InvertBinaryTree: InvertBinaryTree.o
	g++ -g -o InvertBinaryTree.exe InvertBinaryTree.o -pthread    

InvertBinaryTree.o: InvertBinaryTree/InvertBinaryTree.cpp
	g++ -g  -c -pthread InvertBinaryTree/InvertBinaryTree.cpp
