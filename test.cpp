#include <iostream>
#include "chessLib.hpp"

using namespace std;

int main(){
    struct position positionOne;
    positionOne.yatay = 4;
    positionOne.dusey = 'd';
    struct position positionTwo;
    positionTwo.yatay = 5;
    positionTwo.dusey = 'd';
    Piyon piyon1(positionOne);
    Kale kale1(positionOne);
    At at1(positionOne);
    Sah sah1(positionOne);
    //piyon1.printPiece();
    sah1.printPiece();
    movePiece(&sah1, positionTwo);
    sah1.printPiece();

    int i = 0, j = 0;
    boardToArray(i, j, positionOne);
    return 0;
}