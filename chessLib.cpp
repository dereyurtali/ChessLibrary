#include <iostream>

#include "chessLib.h"

using namespace std;



void arrayToChess(int i, int j, struct position pos){ //satir 8 - i
    i = 8 - pos.yatay;
    j = 'a' + pos.dusey;
    cout << "Giris: " << pos.dusey << pos.yatay << "\tCikis: " << i << "-" << j << endl;
};


void Tas::setPos(struct position p1){ this->pos = p1; }
struct position Tas::getPos(){ return this->pos; }
void Tas::setMove(struct position *p1){ this->move = p1; }
struct position* Tas::getMove(){ return this->move; }
Tas::Tas(struct position p1){
    Tas t1;
    t1.setPos(p1); };

Sah::Sah(struct position p1){
    int i,j;
    Sah s1;
    s1.setPos(p1); 
    for (i = 0; i < 8; i++)
    {
       for (j = 0; j < 8; j++)
       {
           board[i][j];
       }
       
    }
    
    
    };
    
Vezir::Vezir(struct position p1){
    Vezir v1;
    v1.setPos(p1); };

Fil::Fil(struct position p1){
    Fil f1;
    f1.setPos(p1); };

At::At(struct position p1){
    At a1;
    a1.setPos(p1); };

Kale::Kale(struct position p1){
    Kale k1;
    k1.setPos(p1); };

Piyon::Piyon(struct position p1){
    Piyon piyon1;
    piyon1.setPos(p1); };

