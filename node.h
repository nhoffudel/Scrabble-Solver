//
// Created by Christian on 10/1/2015.
//

#ifndef PROJECT_2_NODE_H
#define PROJECT_2_NODE_H

#include <iostream>
#include "math.h"
#include <vector>
#include <string>

class node{

public:
    node(std::string key, int value, int x, int y, std::string direction);
    void setKey(std::string key);
    void setValue(int value);
    void setX(int x);
    void setY(int y);
    void setDriection(std::string direction);
    void setNext(int* next);
    void setLast(int* last);
    void toString();

    std::string getKey();
    int getValue();
    int getX();
    int getY();
    std::string getDirection();
    int* getNext();
    int* getLast();
    
    bool equals(node*& rhs);
    
private:
    std::string key;
    int value;
    int x;
    int y;
    std::string direction;
    int* next;
    int* last;

};

#endif //PROJECT_2_NODE_H