#include "helper.h"

helper::helper(){}

map<char, int> helper::create_LV_Map(){
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
    
    return letter_value;
}