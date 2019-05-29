#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include "board.h"
#include "helper.h"

using namespace std;

Board readBoard(string boardName){
    Board b;
    map<char,int> myRack;
    Move answer[225];
    Move answers[225];
    
    ifstream infile(boardName);
    string aword;
    getline(infile, aword);
    for (int l = 0; l < aword.size(); l++){
        if (aword.at(l) == '*'){
            if (myRack.find('*') == myRack.end()){
                myRack.insert(std::pair<char,int>('*', 1));
            }
            else {
                myRack.find('*')->second = myRack.find('*')->second + 1;
            }
        }
        else {
            char achar = aword.at(l) + 32;
            if (myRack.find(achar) == myRack.end()){
                myRack.insert(std::pair<char,int>(achar, 1));
            }
            else{
                myRack.find(achar)->second = myRack.find(achar)->second + 1;
            }
        }
    }
    b.rack = myRack;
    for (int i = 0; i < 15; i++){
        getline(infile, aword);
        for (int j = 0; j < 15; j++){
            if (aword.at(j) == 45){
                b.board[i][j].theChar = 0;
            }
            else if (aword.at(j) >= 65 &&
                    aword.at(j) <= 90){
                b.board[i][j].theChar = aword.at(j) + 32;
                //b.numLetters++;
                
        }
        else {
            b.board[i][j].theChar = 0;
            if ((aword.at(j) - '0') > 3){
                b.board[i][j].wordProp = sqrt(aword.at(j) - '0');
            }
            else b.board[i][j].letterProp = aword.at(j) - '0';
        }
    }
    }
    infile.close();
    
    return b;
}

LinkedList getMoves(Board b){
    helper helper;
    map<char, int> letter_value = helper.create_LV_Map();
    
    Trie root;
    string temp = "";
    vector<string> results;
    ifstream infile("dictionary.txt");
    string word;
    while (getline(infile, word)){
        root.insert(&*word.begin(), word.length());
    }
    infile.close();
    
    b.theTrie = root;
    LinkedList ll;
    
    //if (b.rack.find('*') == b.rack.end()){
    b.wholeRight(ll, letter_value);
    b.wholeDown(ll, letter_value);
    return ll;
    //}
    
    // else{
    //     b.rack.erase('*');
    //     for (char let = 'a'; let <= 'z'; let++){
    //         if (b.rack.find(let) == b.rack.end()){
    //             //cout << "before insert " << b.rack.size() << endl;
    //             b.rack.insert(std::pair<char,int>(let, 1));
    //             b.wholeRight(ll, letter_value);
    //             b.wholeDown(ll, letter_value);
    //             b.rack.erase(let);
    //             //cout << "after erase " << b.rack.size() << endl;
    //         }
    //         else{
    //             //cout << "before insert " << b.rack.size() << endl;
    //             int need = b.rack.find(let)->second + 1;
    //             b.rack.erase(let);
    //             b.rack.insert(std::pair<char,int>(let, need));
    //             b.wholeRight(ll, letter_value);
    //             b.wholeDown(ll, letter_value);
    //             b.rack.erase(let);
    //             b.rack.insert(std::pair<char,int>(let, need - 1));
    //             //cout << "after erase " << b.rack.size() << endl;
    //         }
    //     }
    //     ll.toString();
    // }
    
}

LinkedList getEmptyMoves(Board b){
    LinkedList wordList;
    Trie root;
    ifstream infile("dictionary.txt");
    string word;
    while (getline(infile, word)){
        root.insert(&*word.begin(), word.length());
    }
    infile.close();
    helper helper;
    map<char, int>letter_value = helper.create_LV_Map();
    
    vector<string> results;
    map<char, int> rack = b.rack;
    
    root.getRackWords("", rack, results);
    
    for(vector<string>::iterator it = results.begin(); it!= results.end(); it++){
        string tmp = *it;
        int len = tmp.size();
        int val = 0;
        for(int i = 0; i < len; i++){
            val += letter_value[tmp[i]]; 
        }
        if(len < 5){
            val = val * 2;
            wordList.insert(tmp, val, 8, 8, "RIGHT");
        }else{
            LinkedList shifts;
            int shift = len - 4;
            int fxLoc = 4;
            int bxLoc = 8;
            //Front shift
            for(int i = 0; i < shift; i++){
                int front_val = val + letter_value[tmp[i]];
                front_val = front_val *2;
                if(len ==7){
                    front_val += 50;
                }
                shifts.insert(tmp, front_val, fxLoc, 8, "RIGHT");
                fxLoc -= 1; 
            }
            //Back shift
            for(int i = 0; i < shift; i++){
                int bi = tmp.size() - 1 - i;
                int back_val = val + letter_value[tmp[bi]];
                back_val = back_val *2;
                if(len == 7){
                    back_val += 50;
                }
                shifts.insert(tmp, back_val, bxLoc, 8, "RIGHT");
                bxLoc -= 1; 
            }
            
            wordList.insert(shifts.best_move());
        }
        
    }
    //for(auto& itr : rack)  {
    //     if (itr.first == '*'){
    //         wildcard = true;
    //     }
    // }
    
    // if(wildcard){
    //     map<char,int>::iterator ites;
    //     ites = rack.find('*');
    //     rack.erase(ites);
        
    //     int pt = 0;
    //     for(auto& itm : letter_value)  {
    //         char tmp = itm.first;
    //         pt = letter_value[tmp];
            
    //         map<char,int>::iterator itb;
    //         itb = rack.find(tmp);
    //         if (itb != rack.end()){
    //             rack[tmp] += 1;
    //         }else{
    //             rack[tmp] = 1;
    //         }
            
    //         LinkedList moveList = getEmptyMoves(temp, rack, results, pt);
            
    //         if(rack[tmp] == 1){
    //             map<char,int>::iterator ite;
    //             ite = rack.find(tmp);
    //             rack.erase(ite);
    //         }else{
    //             rack[tmp] -= 1;
    //         }
    //     }
    // }
    return wordList;
}

int main(){
    Board b = readBoard("board.txt");
    
    if (b.isEmpty()){
       LinkedList bestMoves = getEmptyMoves(b);
       bestMoves.toString();
    }else{
        LinkedList bestMoves = getMoves(b);
        bestMoves.toString();
    }
    
    return 0;
}