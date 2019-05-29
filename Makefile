output: main.o helper.o node.o trie.o LinkedList.o board.o
	g++ main.o helper.o node.o trie.o LinkedList.o board.o -o output -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11
	
helper.o: helper.cpp helper.h
	g++ -c helper.cpp
	
LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp node.cpp -std=c++11
	
node.o: node.cpp node.h
	g++ -c node.cpp -std=c++11
	
trie.o: trie.cpp
	g++ -c trie.cpp -std=c++11
	
board.o: board.cpp board.h
	g++ -c board.cpp LinkedList.cpp node.cpp -std=c++11
	
clean:
	rm *.o output
	