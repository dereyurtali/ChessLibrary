#include <iostream>
#include "chessLib.hpp"

using namespace std;

void printPosArray(struct position *p1)
{
    int i = 0;
    while ((*(p1 + i)).dusey != NULL)
    {
        cout << (*(p1 + i)).dusey << (*(p1 + i)).yatay << " ";
        i++;
    }
    cout << endl;
}

// Tas Class'ı
void Tas::setPos(struct position p1) { this->pos = p1; }
struct position Tas::getPos() { return this->pos; }
void Tas::setMove(struct position *p1) { this->move = p1; }
struct position *Tas::getMove() { return this->move; }
Tas::Tas(struct position p1)
{
    this->setPos(p1);
};

struct position *updateSahMove(struct position p1)
{
    int i, j, k = 0;
    struct position *possiblePositions = (struct position *)calloc(8, sizeof(struct position));
    struct position newPos;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (!((j == 1) && (i == 1)))
            {
                newPos.yatay = p1.yatay + (i - 1);
                newPos.dusey = p1.dusey + (j - 1);
                possiblePositions[k++] = newPos;
            }
        }
    }
    return possiblePositions;
}
// Sah Class'ı
Sah::Sah(struct position p1)
{
    this->setPos(p1);
    this->setMove(updateSahMove(p1));
};
void Sah::printPiece()
{
    cout << "Type: Sah" << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}


// Vezir Class'ı
Vezir::Vezir(struct position p1)
{
    int i, j, k = 0;
    this->setPos(p1);

    struct position *possiblePositions = (struct position *)calloc(27, sizeof(struct position));
    struct position newPos;
    // plus code.
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (p1.yatay == (j + 1) || p1.dusey == (i + 'a'))
            {
                newPos.yatay = (j + 1);
                newPos.dusey = i + 'a';
                if (!((p1.dusey == newPos.dusey) && (p1.yatay == newPos.yatay)))
                { // it was showing the p1 position as possible position before this if.
                    possiblePositions[k++] = newPos;
                }
            }
        }
    }
    j = 0;
    // cross code.
    for (i = 0; i < 8; i++)
    {
        newPos.dusey = i + 'a';
        j = newPos.dusey - p1.dusey;
        newPos.yatay = p1.yatay + j;
        if (newPos.yatay > 0)
        {
            if (p1.dusey != newPos.dusey && p1.yatay != newPos.yatay)
            {
                possiblePositions[k++] = newPos;
            }
        }
        newPos.yatay = p1.yatay - j;
        if (newPos.yatay > 0)
        {
            if (p1.dusey != newPos.dusey && p1.yatay != newPos.yatay)
            {
                possiblePositions[k++] = newPos;
            }
        }
    }
    this->setMove(possiblePositions);
};
void Vezir::printPiece()
{
    cout << "Type: Vezir" << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}

// Fil Class'ı
Fil::Fil(struct position p1)
{
    int i, j = 0, k = 0;
    this->setPos(p1);

    struct position *possiblePositions = (struct position *)calloc(16, sizeof(struct position));
    struct position newPos;
    for (i = 0; i < 8; i++)
    {
        newPos.dusey = i + 'a';
        k = newPos.dusey - p1.dusey;
        newPos.yatay = p1.yatay + k;
        if (newPos.yatay > 0)
        {
            if (!(newPos.dusey == 'e' && newPos.yatay == 4))
            {
                possiblePositions[j++] = newPos;
            }
        }
        newPos.yatay = p1.yatay - k;
        if (newPos.yatay > 0)
        {
            if (!(newPos.dusey == 'e' && newPos.yatay == 4))
            {
                possiblePositions[j++] = newPos;
            }
        }
    }
    this->setMove(possiblePositions);
};
void Fil::printPiece()
{
    cout << "Type: Fil" << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}

// At Class'ı
At::At(struct position p1)
{
    int i, j, k = 0, l = 0, m = 0;
    this->setPos(p1);
    struct position *possiblePositions;
    struct position newPos;
    possiblePositions = (struct position *)calloc(8, sizeof(struct position));
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            k = (j + 'a') - p1.dusey;     // k -> yatay farki
            l = (8 - (i + 1)) - p1.yatay; // l -> dusey farki
            if ((k == 1 || k == -1) && (l == 2 || l == -2))
            { // yataydaki fark 1 ise ve duseydeki fark 2 ise
                newPos.yatay = i + 1;
                newPos.dusey = j + 'a';
                possiblePositions[m++] = newPos;
            }
            if ((k == 2 || k == -2) && (l == 1 || l == -1))
            { // yataydaki fark 2 ise ve duseydeki fark 1 ise
                newPos.yatay = i + 1;
                newPos.dusey = j + 'a';
                possiblePositions[m++] = newPos;
            }
        }
    }
    this->setMove(possiblePositions);
};
void At::printPiece()
{
    cout << "Type: At" << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}

// Kale Class'ı
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
void Kale::printPiece()
{
    cout << "Type: Kale" << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}

// Piyon Class'ı
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
void Piyon::printPiece()
{
    cout << "Type: Piyon" << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}

void movePiece(Tas *t, struct position newPos)
{
    struct position *possibleMoves = t->getMove();
    int i = 0;
    bool b = false;
    while ((*(possibleMoves + i)).dusey != NULL)
    {
        if (newPos.dusey == (*(possibleMoves + i)).dusey && newPos.yatay == (*(possibleMoves + i)).yatay)
        {
            b = true;
        }
        i++;
    }
    if (b)
    { //tasi
        t->setPos(newPos);
        
        updateSahMove(newPos);
    }
    else
    {
        cout << "Error:Move is not suitable!" << endl;
    }
}