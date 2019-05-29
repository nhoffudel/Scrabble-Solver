#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

struct Piece{
    char theChar;
    int letterProp;
    int wordProp;
    Piece(){
        letterProp = 1;
        wordProp = 1;
    }
    ~Piece(){};
};

int main(){
    Piece array[15][15];
    ifstream infile("board.txt");
    string temp;
    getline(infile, temp);
    for (int i = 0; i < 15; i++){
        getline(infile, temp);
        for (int j = 0; j < 15; j++){
            if (temp.at(j) == 45){
                array[i][j].theChar = 0;
            }
            else if (temp.at(j) >= 65 &&
                    temp.at(j) <= 90){
                array[i][j].theChar = temp.at(j);
        }
        else {
            array[i][j].theChar = 0;
            if ((temp.at(j) - '0') > 3){
                array[i][j].wordProp = sqrt(temp.at(j) - '0');
            }
            else array[i][j].letterProp = temp.at(j) - '0';
        }
    }
    }
    infile.close();
    cout << array[3][0].theChar << endl;
}