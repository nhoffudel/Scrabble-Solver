#ifndef PROJECT_3_BOARD_H
#define PROJECT_3_BOARD_H

#include <string>
#include <map>
#include <iostream>
#include "trie.cpp"
#include "Move.h"
#include "Piece.h"
#include "LinkedList.h"
using namespace std;

class Board{
    private:
    
    public:
        int numLetters;
        map<char,int> rack;
        Trie theTrie;
        Piece board[15][15];
        
        Board();
        
        ~Board();
        
        bool isEmpty();
        
        int findMoves(Move* answer, int i);
    
        int findMovesDown(Move* answer, int i);
        
        Move isValid(Move* input, int size, string word);
        
        Move findScoreAcross(Move m, map<char,int> map);
        
        Move findScoreDown(Move m, map<char,int> map);
        
        Move checkCrossesAcc(Move m, map<char,int> map);
        
        Move checkCrossesDown(Move m, map<char,int> map);
        
        void wholeRight(LinkedList &ll, map<char,int> letter_value);
        
        void wholeDown(LinkedList &ll, map<char,int> letter_value);
    
    
};
#endif //PROJECT_3_BOARD_H