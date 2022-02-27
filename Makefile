all: Tree.o Forest.o NoFlyweightForest.o NoFlyweightTree.o TreeFactory.o main.o
	g++ -o main main.o Tree.o Forest.o
main.o : Tree.h Forest.h NoFlyweightForest.h NoFlyweightTree.h TreeFactory.h main.cpp
	g++ -c -Wall --std=c++14 main.cpp
Forest.o: Forest.h Forest.cpp Tree.h Tree.cpp
	g++ -c -Wall --std=c++14 Forest.cpp
Tree.o: Tree.h Tree.cpp
	g++ -c -Wall --std=c++14 Tree.cpp
TreeFactory.o: TreeFactory.h TreeFactory.cpp
	g++ -c -Wall --std=c++14 TreeFactory.cpp
NoFlyweightForest.o: NoFlyweightForest.h NoFlyweightForest.cpp NoFlyweightTree.h NoFlyweightTree.cpp
	g++ -c -Wall --std=c++14 NoFlyweightForest.cpp
NoFlyweightTree.o: NoFlyweightTree.h NoFlyweightTree.cpp
	g++ -c -Wall --std=c++14 NoFlyweightTree.cpp
clean:
	rm -rf *.o main