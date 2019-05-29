#ifndef PROJECT_3_PIECE_H
#define PROJECT_3_PIECE_H
struct Piece{
    char theChar;
    int letterProp;
    int wordProp;
    Piece(){
        letterProp = 1; //1 is default, 2 is double, 3 is triple
        wordProp = 1; //1 is default, 2 is double, 3 is triple
    }
    ~Piece(){};
};

#endif //PROJECT_3_PIECE_H