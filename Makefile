prog: main.o AVLNode.o AVLTree.o CancerData.o
    g++ main.o AVLNode.o AVLTree.o CancerData.o -o PA3

AVLTree.o: AVLTree.cpp AVLNode.h
    g++ -c AVLTree.cpp

AVLNode.o: AVLNode.cpp AVLNode.h
    g++ -c AVLNode.cpp

CancerData.o CancerData.cpp CancerData.h
    g++ -c CancerData.cpp

clean:
	-rm *.o

run:
    @./PA3