#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include "math.h"
#include "node.h"
#include <vector>
#include <string>



class LinkedList{

public:
    LinkedList();
    
    void insert(std::string key, int value, int x, int y, std::string direction);
    void insert(node* inNode);
    void rmove(std::string key);
    void toString();

    bool is_in(node*& rhs);
    int size();
    bool is_empty();
    node* best_move();

    ~LinkedList();
private:
    void limitSize();
    int maxLen = 20;
    int* first = 0;
    int* last = 0;
    int length = 0;
};
#endif //LINKED_LIST_H