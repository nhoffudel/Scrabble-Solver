#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <stdlib.h>
#include "trie.cpp"
#include "LinkedList.h"
#include <algorithm>

using namespace std;

LinkedList getEmptyMoves(string temp, map<char, int> rack, vector<string> results, int offset){
    LinkedList wordList;
    Trie root;
    ifstream infile("dictionary.txt");
    string word;
    while (getline(infile, word)){
        root.insert(&*word.begin(), word.length());
    }
    infile.close();
    cout << "=========================================================" << endl;
    for(auto& it : rack)  {
        cout << it.first << " " << it.second << endl;
    }
    
    map<char, int> letter_value;
    letter_value['a'] = 1;
    letter_value['b'] = 3;
    letter_value['c'] = 3;
    letter_value['d'] = 2;
    letter_value['e'] = 1;
    letter_value['f'] = 4;
    letter_value['g'] = 2;
    letter_value['h'] = 2;
    letter_value['i'] = 1;
    letter_value['j'] = 8;
    letter_value['k'] = 5;
    letter_value['l'] = 1;
    letter_value['m'] = 3;
    letter_value['n'] = 1;
    letter_value['o'] = 1;
    letter_value['p'] = 3;
    letter_value['q'] = 10;
    letter_value['r'] = 1;
    letter_value['s'] = 1;
    letter_value['t'] = 1;
    letter_value['u'] = 1;
    letter_value['v'] = 4;
    letter_value['w'] = 4;
    letter_value['x'] = 8;
    letter_value['y'] = 4;
    letter_value['z'] = 10;
    letter_value['*'] = 0;
    
    root.getRackWords(temp, rack, results);
    cout << results.size() << endl;
    for(vector<string>::iterator it = results.begin(); it!= results.end(); it++){
        string tmp = *it;
        int len = tmp.size();
        int val = (len == 7)?50:0;
        for(int i = 0; i < len; i++){
            val += letter_value[tmp[i]]; 
        }
        if(len < 5){
            val -= offset;
            wordList.insert(tmp, val, 8, 8, "RIGHT");
        }else{
            LinkedList shifts;
            int shift = len - 4;
            int fxLoc = 4;
            int bxLoc = 8;
            //Front shift
            for(int i = 0; i < shift; i++){
                int front_val = val + letter_value[tmp[i]] - offset;
                shifts.insert(tmp, front_val, fxLoc, 8, "RIGHT");
                fxLoc -= 1; 
            }
            //Back shift
            for(int i = 0; i < shift; i++){
                int bi = tmp.size() - 1 - i;
                int back_val = val + letter_value[tmp[bi]] - offset;
                shifts.insert(tmp, back_val, bxLoc, 8, "RIGHT");
                bxLoc -= 1; 
            }
            
            wordList.insert(shifts.best_move());
        }
        
    }
    
    return wordList;
}

int main(){
    
    map<char, int> letter_value;
    
    letter_value['a'] = 1;
    letter_value['b'] = 3;
    letter_value['c'] = 3;
    letter_value['d'] = 2;
    letter_value['e'] = 1;
    letter_value['f'] = 4;
    letter_value['g'] = 2;
    letter_value['h'] = 2;
    letter_value['i'] = 1;
    letter_value['j'] = 8;
    letter_value['k'] = 5;
    letter_value['l'] = 1;
    letter_value['m'] = 3;
    letter_value['n'] = 1;
    letter_value['o'] = 1;
    letter_value['p'] = 3;
    letter_value['q'] = 10;
    letter_value['r'] = 1;
    letter_value['s'] = 1;
    letter_value['t'] = 1;
    letter_value['u'] = 1;
    letter_value['v'] = 4;
    letter_value['w'] = 4;
    letter_value['x'] = 8;
    letter_value['y'] = 4;
    letter_value['z'] = 10;
    letter_value['*'] = 0;
    
   
    string temp = "";
    vector<string> results;
    bool wildcard = false;
    
    map<char, int> rack;
    rack['r'] = 1;
    rack['e'] = 1;
    rack['t'] = 1;
    rack['i'] = 1;
    rack['n'] = 1;
    rack['a'] = 1;
    rack['*'] = 1;
    
    
    LinkedList moveList = getEmptyMoves(temp, rack, results, 0);
    
    // for(auto& itr : rack)  {
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
    
    
    moveList.toString();
}