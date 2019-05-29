//
// Created by yes Christian on 10/1/2015.
//

#include "node.h"

node::node(std::string key, int value, int x, int y, std::string direction){
    this->key = key;
    this->value = value;
    this->x = x;
    this->y = y;
    this->direction = direction;
    this->next = 0;
    this->last = nullptr;
}
void node::setKey(std::string key){
    this->key = key;
}
void node::setValue(int value){
    this->value = value;
}
void node::setX(int x){
    this->x = x;
}
void node::setY(int y){
    this->y = y;
}
void node::setDriection(std::string direction){
    this->direction = direction;
}
void node::setNext(int* next){
    this->next = next;
}
void node::setLast(int* last){
    this->last = last;
}

void node::toString(){
    std::cout << "WORD: " << key << " SCORE: " << value << " LOCATION: (" << x << "," << y << ") DIRECTION: " << direction << std::endl;
}

std::string node::getKey(){
    return this->key;
}
int node::getValue(){
    return this->value;
}

int node::getX(){
    return this->x;
}
int node::  getY(){
    return this->y;
}
std::string node::getDirection(){
    return this->direction;
}
int* node::getNext(){
    return this->next;
}
int* node::getLast(){
    return this->last;
}

bool node::equals(node*& rhs) {
    bool answer = false;
    if(this->getKey() == rhs->getKey()){
        if(this->getValue() == rhs->getValue()){
            if(this->getX() == rhs->getX()){
                if(this->getY() == rhs->getY()){
                    if(this->getDirection() == rhs->getDirection()){
                        answer = true;
                    }
                }
            }
        }
    }
    return answer;
}

