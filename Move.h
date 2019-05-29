#ifndef PROJECT_3_MOVE_H
#define PROJECT_3_MOVE_H

struct Move{
    string wordSoFar;
    int x;
    int y;
    int leftSpace;
    int rightSpace;
    string direction;
    int score;
    Move(){};
    ~Move(){};
};

#endif //PROJECT_3_MOVE_H