#include <iostream>
#include "chessLib.h"

using namespace std;

int main(){
    struct position pos;
    pos.yatay = 4;
    pos.dusey = 'd';
    arrayToChess(0,5, pos);
    return 0;
}