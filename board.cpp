#include "board.h"

Board::Board(){
    numLetters = 0;
}

Board::~Board(){}

bool Board::isEmpty(){
    if (board[7][7].wordProp == 2){
        return true;
    }
    else return false;
}

int Board::findMoves(Move* answer, int i){
    int index = 0;
    Move a;
    a.direction = "right";
    int spaces = 0;
    a.wordSoFar = "";
    a.x = 0;
    a.y = 0;
    a.leftSpace = 0;
    a.rightSpace = 0;
    spaces = 0;
        for (int j = 0; j < 15; j++){
            if (!(board[i][j].theChar >= 97 &&
            board[i][j].theChar <= 122)){
            if (a.wordSoFar != ""){
                    answer[index] = a;
                    if (index > 0){
                        if (answer[index - 1].x == a.x){
                        answer[index - 1].rightSpace = a.leftSpace;
                        }
                    }
                    index++;
                
                a.wordSoFar = "";
                spaces = 0;
                spaces++;
            }
            else {
                spaces++;
            }
            }
            
            else if (board[i][j].theChar >= 97 &&
            board[i][j].theChar <= 122 && a.wordSoFar == ""){
                a.x = i;
                a.y = j;
                a.wordSoFar = a.wordSoFar + board[i][j].theChar;
                a.leftSpace = spaces;
                spaces = 0;
            }
            else {
                a.wordSoFar = a.wordSoFar + board[i][j].theChar;
            }
        }
        if (answer[index - 1].rightSpace == 0){
          answer[index - 1].rightSpace = spaces;
    }
    return index;
}

int Board::findMovesDown(Move* answer, int i){
    int index = 0;
    Move a;
    a.direction = "down";
    int spaces = 0;
        a.wordSoFar = "";
        a.x = 0;
        a.y = 0;
        a.leftSpace = 0;
        a.rightSpace = 0;
        spaces = 0;
        for (int j = 0; j < 15; j++){
            if (!(board[j][i].theChar >= 97 &&
            board[j][i].theChar <= 122)){
            if (a.wordSoFar != ""){
                    answer[index] = a;
                    if (index > 0){
                        if (answer[index - 1].y == a.y){
                        answer[index - 1].rightSpace = a.leftSpace;
                        }
                    }
                    index++;
                
                a.wordSoFar = "";
                spaces = 0;
                spaces++;
            }
            else {
                spaces++;
            }
            }
            
            else if (board[j][i].theChar >= 97 &&
            board[j][i].theChar <= 122 && a.wordSoFar == ""){
                a.x = j;
                a.y = i;
                a.wordSoFar = a.wordSoFar + board[j][i].theChar;
                a.leftSpace = spaces;
                spaces = 0;
            }
            else {
                a.wordSoFar = a.wordSoFar + board[j][i].theChar;
            }
        }
        if (answer[index - 1].rightSpace == 0){
          answer[index - 1].rightSpace = spaces;
    }
    return index;
}

Move Board::isValid(Move* input, int size, string word){
    Move answer;
    answer.score = -1;
    answer.wordSoFar = word;
    int prevIndex = 0;
    int prevSize;
    int index;
    for (int i = 0; i < size; i++){
        if (word == input[i].wordSoFar){
            answer.score = -1;
            return answer;
        }
        index = word.find(input[i].wordSoFar, prevIndex);
        if (answer.score < 0){
            if (i != 0){
                if (input[i].leftSpace <= index){
                    //cout << "WHAT UP" << endl;
                    answer.score = -1;
                    return answer;
                    
                }
            }
            if (index < word.size() && (index >= 0)){
            if (input[i].leftSpace >= index &&
            ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) < 
            input[i].rightSpace){
                if (input[i].direction == "right"){
                    answer.score = 1;
                    answer.x = input[i].x;
                    answer.y = input[i].y - index;
                    answer.direction = "right";
                  
                return answer;
            }
            else {
                answer.score = 1;
                answer.x = input[i].x - index;
                answer.y = input[i].y;
                answer.direction = "down";
                return answer;
            }
            }
            else if (input[i].leftSpace >= index &&
            ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) == 
            input[i].rightSpace){
                if (input[i].direction == "right"){
                    if (i == size - 1){
                    answer.score = 1;
                    answer.x = input[i].x;
                    answer.y = input[i].y - index;
                    answer.direction = "right";
                     
                    return answer;
            }
            else {
                    answer.score = -1;
                    answer.x = input[i].x;
                    answer.y = input[i].y - index;
                    answer.direction = "right";
                     
                    return answer;
            }
                }
            else {
                if (i == size - 1){
                answer.score = 1;
                answer.x = input[i].x - index;
                answer.y = input[i].y;
                answer.direction = "down";
                return answer;
            }
            else {
                answer.score = -1;
                answer.x = input[i].x - index;
                answer.y = input[i].y;
                answer.direction = "down";
                return answer;
            }
                }
                }
            else if (input[i].leftSpace >= index &&
            ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) > 
            input[i].rightSpace){
                if (input[i].direction == "right"){
                    answer.score = 1;
                    answer.x = input[i].x;
                    answer.y = input[i].y - index;
                    answer.direction = "right";
                    prevIndex = index;
                    prevSize = input[i].wordSoFar.size();
                    if (i == size - 1){
                        answer.score = -1;
                        return answer;
                    }
                    else continue;
                }
                else {
                    answer.score = 1;
                    answer.y = input[i].y;
                    answer.x = input[i].x - index;
                    answer.direction = "down";
                    prevIndex = index;
                    prevSize = input[i].wordSoFar.size();
                    if (i == size - 1){
                        answer.score = -1;
                        return answer;
                    }
                    else continue;
                }
            }
            }
            }
        else if (answer.score >= 0){
            if (index > word.size() || (index < 0)){
                answer.score = -1;
                return answer;
            }
            else if (index < word.size() && (index >= 0)){
            if (((index - (prevIndex + (prevSize - 1))) - 1) != input[i].leftSpace){
                answer.score = -1;
                return answer;
            }
            if (input[i].leftSpace >= (index - (prevIndex + prevSize)) &&
            ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) < 
            input[i].rightSpace){
                return answer;
            }
            
            else if (input[i].leftSpace >= (index - (prevIndex + prevSize)) &&
            ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) == 
            input[i].rightSpace){
                if (input[i].direction == "right"){
                    if (i == size - 1){
                    answer.score = 1;
                    return answer;
            }
            else {
                    answer.score = -1;
                    return answer;
            }
                }
            else {
                if (i == size - 1){
                answer.score = 1;
                return answer;
            }
            else {
                answer.score = -1;
                return answer;
            }
                }
                }
            else if (input[i].leftSpace >= (index - (prevIndex + prevSize)) &&
            ((word.size() - 1) - (index + (input[i].wordSoFar.size() - 1))) > 
            input[i].rightSpace){
                if (i == size - 1){
                    answer.score = -1;
                    return answer;
                }
                else{
                if (input[i].direction == "right"){
                    answer.score = 1;
                    prevIndex = index;
                    prevSize = input[i].wordSoFar.size();
                    continue;
                }
                else {
                    answer.score = 1;
                    prevIndex = index;
                    prevSize = input[i].wordSoFar.size();
                    continue;
                }
            }
            }
            prevIndex = index;
            prevSize = input[i].wordSoFar.size();
        }
}
}
return answer;
}

Move Board::findScoreAcross(Move m, map<char,int> map){
    Move move;
    bool shouldDouble;
    bool shouldTriple;
    if (m.score == -1){
        move = m;
        return move;
    }
    int temp = 0;
    for (int j = m.y, i = m.x, k = 0; j < m.y + m.wordSoFar.size(); j++, k++){
            if (board[i][j].wordProp == 2){
                    shouldDouble = true;
                }
                if (board[i][j].wordProp == 3){
                    shouldTriple = true;
                }
                if (board[i][j].wordProp == 1){
                    
                }
                temp = temp + (board[i][j].letterProp * map.find(m.wordSoFar.at(k))->second);
                 
            }
        
        if (shouldDouble == true){
            temp = temp * 2;
        }
        if (shouldTriple == true){
            temp = temp * 3;
        }
        m.score = m.score + temp;
        move = m;
    return move;
}

Move Board::findScoreDown(Move m, map<char,int> map){
    Move move;
    bool shouldDouble;
    bool shouldTriple;
    if (m.score == -1){
        move = m;
        return move;
    }
    int temp = 0;
    for (int i = m.x, j = m.y, k = 0; i < m.x + m.wordSoFar.size(); i++, k++){
                if (board[i][j].wordProp == 2){
                    shouldDouble = true;
                }
                if (board[i][j].wordProp == 3){
                    shouldTriple = true;
                }
                if (board[i][j].wordProp == 1){
                    
                }
                temp = temp + (board[i][j].letterProp * map.find(m.wordSoFar.at(k))->second);
                 
            }
        
        if (shouldDouble == true){
            temp = temp * 2;
        }
        if (shouldTriple == true){
            temp = temp * 3;
        }
        m.score = m.score + temp;
        move = m;
        return move;
}

Move Board::checkCrossesAcc(Move m, map<char,int> map){
    Move move;
    bool shouldDouble;
    bool shouldTriple;
    if (m.score == -1){
        move = m;
        return move;
    }
    m.score = 0;
        for (int j = m.y, i = m.x, k = 0 ; j < (m.y + m.wordSoFar.size()); j++, k++){
        
        shouldDouble = false;
        shouldTriple = false;
        int temp = 0;
        if (board[i][j].theChar >= 97 && board[i][j].theChar <= 122){
            continue;
        }
        int newI = i;
        string newWord = "";
        newI--;
        while (newI >= 0 && (board[newI][j].theChar >= 97 &&
            board[newI][j].theChar <= 122)){
            newI--;
        }
        newI++;
        
        int newVar = 0;
        while (newI < 15){
            if (newI == m.x){
                if (board[newI][j].theChar >= 97 &&
            board[newI][j].theChar <= 122){
                newWord = newWord + board[newI][j].theChar;
                temp = temp + (board[newI][j].letterProp * map.find(newWord.at(newWord.size() - 1))->second);
                
                if (board[newI][j].wordProp == 2){
                    shouldDouble = true;
                }
                if (board[newI][j].wordProp == 3){
                    shouldTriple = true;
                }
                newI++;
                newVar++;
                continue;
            }
                else {
                    newWord = newWord + m.wordSoFar.at(j - m.y);
                temp = temp + (board[newI][j].letterProp * map.find(newWord.at(newWord.size() - 1))->second);
                
                if (board[newI][j].wordProp == 2){
                    shouldDouble = true;
                }
                if (board[newI][j].wordProp == 3){
                    shouldTriple = true;
                }
                newI++;
                newVar++;
                continue;
                }
            }
            else if (board[newI][j].theChar >= 97 &&
            board[newI][j].theChar <= 122){
                newWord = newWord + board[newI][j].theChar;
                temp = temp + (board[newI][j].letterProp * map.find(newWord.at(newWord.size() - 1))->second);
                
                if (board[newI][j].wordProp == 2){
                    shouldDouble = true;
                }
                if (board[newI][j].wordProp == 3){
                    shouldTriple = true;
                }
                newI++;
                newVar++;
            }
            else{
                break;
            }
        }
        if (newWord.size() == 1){
            
            continue;
        }
        else if (theTrie.hasWord(&*newWord.begin(), newWord.size())){
            if (shouldDouble == true){
                temp = temp * 2;
                m.score = m.score + temp;
                
            }
            else if (shouldTriple == true){
                temp = temp * 3;
                m.score = m.score + temp;
                
            }
            else {
                m.score = m.score + temp;
            }
            continue;
        }
        else {
            m.score = -1;
            move = m;
            return move;
        }
        }
        move = m;
        return move;
}

Move Board::checkCrossesDown(Move m, map<char,int> map){
    Move move;
    bool shouldDouble;
    bool shouldTriple;
    if (m.score == -1){
        move = m;
        return move;
    }
    m.score = 0;
        for (int j = m.y, i = m.x, k = 0 ; i < (m.x + m.wordSoFar.size()); i++, k++){
        shouldDouble = false;
        shouldTriple = false;
        int temp = 0;
        if (board[i][j].theChar >= 97 && board[i][j].theChar <= 122){
            continue;
        }
        int newJ = j;
        string newWord = "";
        newJ--;
        while (newJ >= 0 && (board[i][newJ].theChar >= 97 &&
            board[i][newJ].theChar <= 122)){
            newJ--;
        }
        newJ++;
       
        int newVar = 0;
        while (newJ < 15){
            if (newJ == m.y){
                if (board[i][newJ].theChar >= 97 &&
            board[i][newJ].theChar <= 122){
                newWord = newWord + board[i][newJ].theChar;
                temp = temp + (board[i][newJ].letterProp * map.find(newWord.at(newWord.size() - 1))->second);
                
                if (board[i][newJ].wordProp == 2){
                    shouldDouble = true;
                }
                if (board[i][newJ].wordProp == 3){
                    shouldTriple = true;
                }
                newJ++;
                newVar++;
                
                continue;
            }
                else {
                    newWord = newWord + m.wordSoFar.at(i - m.x);
                temp = temp + (board[i][newJ].letterProp * map.find(newWord.at(newWord.size() - 1))->second);
                
                if (board[i][newJ].wordProp == 2){
                    shouldDouble = true;
                }
                if (board[i][newJ].wordProp == 3){
                    shouldTriple = true;
                }
                newJ++;
                newVar++;
                continue;
                }
            }
            else if (board[i][newJ].theChar >= 97 &&
            board[i][newJ].theChar <= 122){
                newWord = newWord + board[i][newJ].theChar;
                temp = temp + (board[i][newJ].letterProp * map.find(newWord.at(newWord.size() - 1))->second);
                
                if (board[i][newJ].wordProp == 2){
                    shouldDouble = true;
                }
                if (board[i][newJ].wordProp == 3){
                    shouldTriple = true;
                }
                newJ++;
                newVar++;
            }
            else{
                break;
            }
        }
        if (newWord.size() == 1){
            continue;
        }
        else if (theTrie.hasWord(&*newWord.begin(), newWord.size())){
            if (shouldDouble == true){
                
                temp = temp * 2;
                m.score = m.score + temp;
            }
            if (shouldTriple == true){
                temp = temp * 3;
                m.score = m.score + temp;
            }
            else{
                m.score = m.score + temp;
            }
            continue;
        }
        else {
            m.score = -1;
            move = m;
            return move;
        }
        }
        move = m;
        return move;
}

void Board::wholeRight(LinkedList &ll, map<char,int> letter_value){
    string temp = "";
    for (int k = 0; k < 15; k++){
    Move answer[50];
    int z = findMoves(answer, k);
    for (int m = 0; m < z; m++){
        string s = answer[m].wordSoFar;
        for (int n = 0; n < s.size(); n++){
            char ac = s.at(n);
            if (rack.find(ac) == rack.end()){
                rack.insert(std::pair<char,int>(ac, 1));
            }
            else{
                rack.find(ac)->second = rack.find(ac)->second + 1;
        }
        }
        vector<string> results;
        theTrie.getRackWords(temp, rack, results);
        for(vector<string>::iterator it = results.begin(); it!= results.end(); it++){
            Move m = isValid(answer, z, *it);
            if (m.score == -1){
                continue;
            }
            m = checkCrossesAcc(m, letter_value);
            m = findScoreAcross(m, letter_value);
            if (m.score != -1){
                ll.insert(m.wordSoFar, m.score, m.y + 1, m.x + 1, m.direction);
            }
    }
      for (int p = 0; p < s.size(); p++){
          char aa = s.at(p);
          if (rack.find(aa)->second == 1){
              rack.erase(aa);
          }
          else {
              int need = rack.find(aa)->second - 1;
              rack.erase(aa);
              rack.insert(std::pair<char,int>(aa, need));
          }
      } 
    }
    
}

}

void Board::wholeDown(LinkedList &ll, map<char,int> letter_value){
    string temp = "";
    for (int q = 0; q < 15; q++){
    Move answers[50];
    int y = findMovesDown(answers, q);
    for (int r = 0; r < y; r++){
        string t = answers[r].wordSoFar;
        for (int u = 0; u < t.size(); u++){
            char ab = t.at(u);
            if (rack.find(ab) == rack.end()){
                rack.insert(std::pair<char,int>(ab, 1));
            }
            else{
                rack.find(ab)->second = rack.find(ab)->second + 1;
        }
        }
        vector<string> results;
        theTrie.getRackWords(temp, rack, results);
        for(vector<string>::iterator it = results.begin(); it!= results.end(); it++){
            Move mv = isValid(answers, y, *it);
            if (mv.score == -1){
                continue;
            }
            mv = checkCrossesDown(mv, letter_value);
            mv = findScoreDown(mv, letter_value);
            if (mv.score != -1){
                ll.insert(mv.wordSoFar, mv.score, mv.y + 1, mv.x + 1, mv.direction);
            }
    }
      for (int v = 0; v < t.size(); v++){
          char abc = t.at(v);
          if (rack.find(abc)->second == 1){
              rack.erase(abc);
          }
          else {
              int need = rack.find(abc)->second - 1;
              rack.erase(abc);
              rack.insert(std::pair<char,int>(abc, need));
          }
      } 
    }
    
}
}
