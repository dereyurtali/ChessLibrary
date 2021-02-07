#include <iostream>
#include "chessLib.h"

using namespace std;

struct position
{
    char dusey;
    short yatay;
};


void Tas::setPos(struct position p1){ this->pos = p1; }
struct position Tas::getPos(){ return this->pos; }
Tas::Tas(struct position p1){
    Tas t1;
    t1.setPos(p1);
};
void Tas::setMove(struct position *p1){ this->move = p1; }
struct position* Tas::getMove(){ return this->move; }
