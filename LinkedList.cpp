#include "LinkedList.h"


LinkedList::LinkedList(){};

void LinkedList::insert(std::string key, int value, int x, int y, std::string direction){
    node *newNode = new node(key, value, x, y, direction);
    if(is_empty()){
        first = (int *) newNode;
        last = (int *) newNode;
        length = 1;
    }else if(is_in(newNode)){
        return;
    }else{
        node *me = (node *) first;
        bool found = false;

        if(me->getValue() < value){
            newNode->setNext((int*) me);
            me->setLast((int*) newNode);
            
            first = (int*) newNode;
            found = true;
        }
        
        while (!found){
            if(me->getNext() != 0){
                node *next = (node *) me->getNext();
                if(me->getValue() > value && next->getValue() < value || me->getValue() == value){
                    me->setNext((int *) newNode);
                    next->setLast((int *) newNode);
                    
                    newNode->setLast((int*) me);
                    newNode->setNext((int*) next);
                    
                    found = true;
                }else{
                    me = (node *) me->getNext();
                } 
            }else{
                me->setNext((int*) newNode);
                newNode->setLast((int*) me);
                last = (int*) newNode;
                found = true;   
            }
        }
        length += 1;
    }
    limitSize();
}
void LinkedList::insert(node* inNode){
    insert(inNode->getKey(), inNode->getValue(), inNode->getX(), inNode->getY(), inNode->getDirection());
}
void LinkedList::rmove(std::string key){
    bool found = false;
    node *me = (node *) first;
    node *lasts = (node *) last;

    if(me->getKey() == key){//trying to remove first node in list
        found = true;
        node *next = (node *) me->getNext();
        next->setLast(nullptr);
        first = (int *) next;
        delete me;
    }
    if(lasts->getKey() == key && found == false){//trying to remove last node in list
        found = true;
        node *prev = (node *) lasts->getLast();
        prev->setNext(0);
        last = (int *) prev;
        delete lasts;
    }

    while(!found){
        if (me->getKey() == key){
            found = true;
            node *last = (node *) me->getLast();
            node *next = (node *) me->getNext();

            last->setNext((int *) next);
            next->setLast((int *) last);

            delete me;
        }else{
            if (me->getNext() == 0){
                found = true;
            }else{
                me = (node *) me->getNext();
            }
        }
    }
}
void LinkedList::toString(){
    bool isEnd = false;
    if (first == 0){
        std::cout << "The List is Empty" << std::endl;
        return;
    }
    
    node *me = (node *) first;
    while(!isEnd){

        me->toString();

        if (me->getNext() == 0){
            isEnd = true;
        }else{
            me = (node *) me->getNext();
        }
    }
}

bool LinkedList::is_in(node*& rhs){
    bool found = false;
    node *me = (node *) first;
    if(is_empty()){
        return false;
    }
    while(!found){
        if (me->equals(rhs)){
            return true;
        }else{
            if (me->getNext() == 0){
                return false;
            }else{
                me = (node *) me->getNext();
            }
        }
    }
}
int LinkedList::size(){
    return length;
}
bool LinkedList::is_empty(){
    if (length > 0){
        return false;
    }else{
        return true;
    }
}
node* LinkedList::best_move(){
    return (node *) first;
}

LinkedList::~LinkedList(){
    if(length > 0){
        node *me = (node *) first;
        while(me->getNext() != 0){
            node *next = (node *) me->getNext();
            delete me;
            me = next;
    
        }
        delete me;
    }
}


void LinkedList::limitSize(){
    if(length > maxLen){
        node *tail = (node *) last;
        node *newTail = (node *) tail->getLast();
        newTail->setNext(0);
        last = (int *) newTail;
        delete tail;
        length = maxLen;
    }
    
}