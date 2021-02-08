#include <iostream>
#include "chessLib.hpp"

using namespace std;
/*
void arrayToChess(int i, int j, struct position pos)
{ //satir 8 - i
    i = 8 - pos.yatay;
    j = 'a' + pos.dusey;
    cout << "Giris: " << pos.dusey << pos.yatay << "\tCikis: " << i << "-" << j << endl;
};
*/
/*
Tas **board = (Tas **)malloc(8 * sizeof(Tas *));
for (int i = 0; i < 8; i++) {
    board[i] = (Tas *)malloc(8 * sizeof(Tas));
}
*/

void Tas::setPos(struct position p1) { this->pos = p1; }
struct position Tas::getPos() { return this->pos; }
void Tas::setMove(struct position *p1) { this->move = p1; }
struct position *Tas::getMove() { return this->move; }
Tas::Tas(struct position p1)
{
    this->setPos(p1);
};
/*
Sah::Sah(struct position p1)
{
    this->setPos(p1);
    
};

Vezir::Vezir(struct position p1)
{
    this->setPos(p1);

};

Fil::Fil(struct position p1)
{
    this->setPos(p1);
   
};

At::At(struct position p1)
{
   this->setPos(p1);
  
};

*/

Kale::Kale(struct position p1)
{
    int i, j, k = 0;
    this->setPos(p1);

    struct position *possiblePositions = (struct position *)calloc(14, sizeof(struct position));
    struct position newPos;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (p1.yatay == (j + 1) || p1.dusey == (i + 'a'))
            {
                newPos.yatay = (j + 1);
                newPos.dusey = i + 'a';
                if (!(newPos.dusey == 'e' && newPos.yatay == 4))
                {
                    possiblePositions[k++] = newPos;
                }
            }
        }
    }
    this->setMove(possiblePositions);
};

Piyon::Piyon(struct position p1)
{
    int i;
    this->setPos(p1);

    struct position *possiblePositions;
    struct position newPos;
    if (p1.yatay == 2)
    {
        struct position *foo = (struct position *)calloc(2, sizeof(struct position));
        for (i = 0; i < 2; i++)
        {
            newPos.yatay = p1.yatay + (i + 1);
            newPos.dusey = p1.dusey;
            foo[i] = newPos;
        }
        possiblePositions = foo;
    }
    else
    {
        struct position *foo = (struct position *)calloc(1, sizeof(struct position));
        newPos.yatay = p1.yatay + 1;
        newPos.dusey = p1.dusey;
        foo[0] = newPos;
        possiblePositions = foo;
    }
    this->setMove(possiblePositions);
};

/*
void Sah::printPiece()
{
    struct position *foo = this->getMove();
    int i;
    cout << "Type: Sah\n"
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl;
    cout << "\n"
         << "Possible Moves: ";
    for (struct position &poses : foo)
        cout << poses.dusey << poses.yatay << " ";
    cout << endl;
}


void movePiece(Sah *s1, struct position newP)
{
    s1->setPos(&newP);
}
*/
