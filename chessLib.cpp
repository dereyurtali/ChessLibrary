#include <iostream>

#include "chessLib.h"

using namespace std;

void arrayToChess(int i, int j, struct position pos)
{ //satir 8 - i
    i = 8 - pos.yatay;
    j = 'a' + pos.dusey;
    cout << "Giris: " << pos.dusey << pos.yatay << "\tCikis: " << i << "-" << j << endl;
};

void Tas::setPos(struct position p1) { this->pos = p1; }
struct position Tas::getPos() { return this->pos; }
void Tas::setMove(struct position *p1) { this->move = p1; }
struct position *Tas::getMove() { return this->move; }
Tas::Tas(struct position p1)
{
    Tas t1;
    t1.setPos(p1);
};

Sah::Sah(struct position p1)
{
    Sah s1;
    s1.setPos(p1);
    int i, j, k=0;
    struct Poz *possiblePositions = (struct Poz *)calloc(8, sizeof(struct Poz));
    struct Poz new;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if( !((j==1) && (i==1)) ){
                new.yatay = old.yatay+(i-1);
                new.dusey = old.dusey+(j-1);
                possiblePositions[k++] = new;
            }
        }
    }
    s1.setMove(possiblePositions);
};

Vezir::Vezir(struct position p1)
{
    Vezir v1;
    v1.setPos(p1);
    int i, j, k=0;
    struct Poz *possiblePositions = (struct Poz *)calloc(27, sizeof(struct Poz));
    struct Poz new;
    // plus code.
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (old.yatay == (j+1) || old.dusey == (i+'a')) {
                new.yatay = (j+1);
                new.dusey = i+'a';
                if(!((old.dusey == new.dusey) && (old.yatay == new.yatay))){ // it was showing the old position as possible position before this if.
                    possiblePositions[k++] = new;
                }
            }
        }
    }j = 0;
    // cross code.
    for (i = 0; i < 8; i++) {
        new.dusey = i+'a';
        j = new.dusey - old.dusey;
        new.yatay = old.yatay + j;
        if (new.yatay > 0){
            if(old.dusey != new.dusey && old.yatay != new.yatay){
                possiblePositions[k++] = new;
            }
        }
        new.yatay = old.yatay - j;
        if (new.yatay > 0){
            if(old.dusey != new.dusey && old.yatay != new.yatay){
                possiblePositions[k++] = new;
            }
        }
    }
    v1.setMove(possiblePositions);
};

Fil::Fil(struct position p1)
{
    Fil f1;
    f1.setPos(p1);
    int i, j = 0, k = 0;
    struct Poz *possiblePositions = (struct Poz *)calloc(16, sizeof(struct Poz));
    struct Poz new;
    for (i = 0; i < 8; i++)
    {
        new.dusey = i + 'a';
        k = new.dusey - old.dusey;
        new.yatay = old.yatay + k;
        if (new.yatay > 0)
        {
            if (!(new.dusey == 'e' && new.yatay == 4))
            {
                possiblePositions[j++] = new;
            }
        }
        new.yatay = old.yatay - k;
        if (new.yatay > 0)
        {
            if (!(new.dusey == 'e' && new.yatay == 4))
            {
                possiblePositions[j++] = new;
            }
        }
    }
    f1.setMove(possiblePositions);
};

At::At(struct position p1)
{
    At a1;
    a1.setPos(p1);
    int i, j, k = 0, l = 0, m = 0;
    struct Poz *possiblePositions;
    struct Poz new;
    possiblePositions = (struct Poz *)calloc(8, sizeof(struct Poz));
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            k = (j + 'a') - old.dusey;     // k -> yatay farki
            l = (8 - (i + 1)) - old.yatay; // l -> dusey farki
            if ((k == 1 || k == -1) && (l == 2 || l == -2))
            { // yataydaki fark 1 ise ve duseydeki fark 2 ise
                new.yatay = i + 1;
                new.dusey = j + 'a';
                possiblePositions[m++] = new;
            }
            if ((k == 2 || k == -2) && (l == 1 || l == -1))
            { // yataydaki fark 2 ise ve duseydeki fark 1 ise
                new.yatay = i + 1;
                new.dusey = j + 'a';
                possiblePositions[m++] = new;
            }
        }
    }
    a1.setMove(possiblePositions);
};

Kale::Kale(struct position p1)
{
    Kale k1;
    k1.setPos(p1);
    int i, j, k = 0;
    struct Poz *possiblePositions = (struct Poz *)calloc(14, sizeof(struct Poz));
    struct Poz new;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (old.yatay == (j + 1) || old.dusey == (i + 'a'))
            {
                new.yatay = (j + 1);
                new.dusey = i + 'a';
                if (!(new.dusey == 'e' && new.yatay == 4))
                {
                    possiblePositions[k++] = new;
                }
            }
        }
    }
    k1.setMove(possiblePositions);
};

Piyon::Piyon(struct position p1)
{
    Piyon piyon1;
    piyon1.setPos(p1);
    struct Poz *possiblePositions;
    struct Poz new;
    if (old.yatay == 2)
    {
        struct Poz *foo = (struct Poz *)calloc(2, sizeof(struct Poz));
        for (int i = 0; i < 2; i++)
        {
            new.yatay = old.yatay + (i + 1);
            new.dusey = old.dusey;
            foo[i] = new;
        }
        possiblePositions = foo;
    }
    else
    {
        struct Poz *foo = (struct Poz *)calloc(1, sizeof(struct Poz));
        new.yatay = old.yatay + 1;
        new.dusey = old.dusey;
        foo[0] = new;
        possiblePositions = foo;
    }
    possiblePositions;
    piyon1.setMove(possiblePositions);
};

void Sah::printPiece(){
    struct Poz *foo = this -> getMove();
    int i;
    cout << "Type: Sah\n" << "Current Pos: " << this -> pos.dusey << this -> pos.yatay << endl;
    cout << "\n" << "Possible Moves: ";
    for(const struct position &poses : foo)
        cout << poses.dusey << poses.yatay << " ";
    cout << endl;
}
void Vezir::printPiece(){
    struct Poz *foo = this -> getMove();
    int i;
    cout << "Type: Vezir\n" << "Current Pos: " << this -> pos.dusey << this -> pos.yatay << endl;
    cout << "\n" << "Possible Moves: ";
    for(const struct position &poses : foo)
        cout << poses.dusey << poses.yatay << " ";
    cout << endl;
}
void Fil::printPiece(){
    struct Poz *foo = this -> getMove();
    int i;
    cout << "Type: Fil\n" << "Current Pos: " << this -> pos.dusey << this -> pos.yatay << endl;
    cout << "\n" << "Possible Moves: ";
    for(const struct position &poses : foo)
        cout << poses.dusey << poses.yatay << " ";
    cout << endl;
}
void At::printPiece(){
    struct Poz *foo = this -> getMove();
    int i;
    cout << "Type: At\n" << "Current Pos: " << this -> pos.dusey << this -> pos.yatay << endl;
    cout << "\n" << "Possible Moves: ";
    for(const struct position &poses : foo)
        cout << poses.dusey << poses.yatay << " ";
    cout << endl;
}
void Kale::printPiece(){
    struct Poz *foo = this -> getMove();
    int i;
    cout << "Type: Kale\n" << "Current Pos: " << this -> pos.dusey << this -> pos.yatay << endl;
    cout << "\n" << "Possible Moves: ";
    for(const struct position &poses : foo)
        cout << poses.dusey << poses.yatay << " ";
    cout << endl;
}
void Piyon::printPiece(){
    struct Poz *foo = this -> getMove();
    int i;
    cout << "Type: Piyon\n" << "Current Pos: " << this -> pos.dusey << this -> pos.yatay << endl;
    cout << "\n" << "Possible Moves: ";
    for(const struct position &poses : foo)
        cout << poses.dusey << poses.yatay << " ";
    cout << endl;
}