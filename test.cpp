#include <iostream>
#include "chessLib.hpp"

using namespace std;

int main(){
    struct position positionOne;
    positionOne.yatay = 4;
    positionOne.dusey = 'd';
    Piyon piyon1(positionOne);
    Kale kale1(positionOne);
    return 0;
}