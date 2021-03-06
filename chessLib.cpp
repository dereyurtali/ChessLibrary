#include <iostream>
#include "chessLib.hpp"

using namespace std;

Tas **createTasArray(int a, int b)
{
    // Board tanimlandi
    Tas **board = (Tas **)malloc(a * sizeof(Tas *));
    for (int i = 0; i < a; i++)
    {
        board[i] = (Tas *)malloc(b * sizeof(Tas));
    }
    return board;
}
Tas *createTasArray(int a)
{
    // Board tanimlandi
    Tas *board = (Tas *)malloc(a * sizeof(Tas));
    return board;
}

struct ij boardToArray(struct position pos)
{
    struct ij rtr;
    rtr.i = 8 - pos.yatay;
    rtr.j = pos.dusey - 'a';
    return rtr;
}

struct position arrayToBoard(struct ij inputIJ)
{
    struct position pos;
    pos.dusey = inputIJ.j + 'a';
    pos.yatay = 8 - inputIJ.i;
    return pos;
}

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

// Tas Class'i
void Tas::setPos(struct position p1) { this->pos = p1; }
struct position Tas::getPos() { return this->pos; }
void Tas::setMove(struct position *p1) { this->move = p1; }
struct position *Tas::getMove() { return this->move; }
void Tas::setTasTuru(string s1){ this->tasTuru = s1; }
string Tas::getTasTuru(){ return this->tasTuru; }
    
Tas::Tas(struct position p1)
{
    this->setPos(p1);
};

// --------------- SAH -----------------
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
// Sah Class'i
Sah::Sah(struct position p1)
{
    this->setTasTuru("Sah");
    this->setPos(p1);
    this->setMove(updateSahMove(p1));
};
void Sah::printPiece()
{
    cout << "Type: " << this->getTasTuru() << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}
// --------------- SAH -----------------

// --------------- VEZIR -----------------
struct position *updateVezirMove(struct position p1)
{
    int i, j, k = 0;
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
    return possiblePositions;
}
// Vezir Class'ı
Vezir::Vezir(struct position p1)
{
    this->setTasTuru("Vezir");
    this->setPos(p1);
    this->setMove(updateVezirMove(p1));
};
void Vezir::printPiece()
{
    cout << "Type: " << this->getTasTuru() << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}
// --------------- VEZIR -----------------

//

// --------------- FIL -----------------
struct position *updateFilMove(struct position p1)
{
    int i, j = 0, k = 0;
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
    return possiblePositions;
}
// Fil Class'ı
Fil::Fil(struct position p1)
{
    this->setTasTuru("Fil");
    this->setPos(p1);
    this->setMove(updateFilMove(p1));
};
void Fil::printPiece()
{
    cout << "Type: " << this->getTasTuru() << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}
// --------------- FIL -----------------

//

// --------------- AT -----------------
struct position *updateAtMove(struct position p1)
{
    int i, j, k = 0, l = 0, m = 0;
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
    return possiblePositions;
}
// At Class'ı
At::At(struct position p1)
{
    this->setTasTuru("At");
    this->setPos(p1);
    this->setMove(updateAtMove(p1));
};
void At::printPiece()
{
    cout << "Type: " << this->getTasTuru() << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}
// --------------- AT -----------------

//

// --------------- KALE -----------------
struct position *updateKaleMove(struct position p1)
{
    int i, j, k = 0;
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
    return possiblePositions;
}
// Kale Class'ı
Kale::Kale(struct position p1)
{
    this->setTasTuru("Kale");
    this->setPos(p1);
    this->setMove(updateKaleMove(p1));
};
void Kale::printPiece()
{
    cout << "Type: " << this->getTasTuru() << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}
// --------------- KALE -----------------

//

// --------------- PIYON -----------------
struct position *updatePiyonMove(struct position p1)
{
    int i;
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
    return possiblePositions;
}
// Piyon Class'ı
Piyon::Piyon(struct position p1)
{
    this->setTasTuru("Piyon");
    this->setPos(p1);
    this->setMove(updatePiyonMove(p1));
};
void Piyon::printPiece()
{
    cout << "Type: " << this->getTasTuru() << endl
         << "Current Pos: " << this->getPos().dusey << this->getPos().yatay << endl
         << "Possible Moves: ";
    printPosArray(this->getMove());
}
// --------------- PIYON -----------------

//
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
        free(t->getMove());
        if ( !(t->getTasTuru().compare("At")) ){ updateAtMove(newPos); }
        else if ( !(t->getTasTuru().compare("Vezir")) ){ updateVezirMove(newPos); }
        else if ( !(t->getTasTuru().compare("Piyon")) ){ updateAtMove(newPos); }
        else if ( !(t->getTasTuru().compare("Sah")) ){ updateSahMove(newPos); }
        else if ( !(t->getTasTuru().compare("Kale")) ){ updateKaleMove(newPos); }
        else if ( !(t->getTasTuru().compare("Fil")) ){ updateFilMove(newPos); }
        /*
        switch (t->getTasTuru())
        {
        case "At":
            updateAtMove(newPos);
            break;
        case "Vezir":
            updateVezirMove(newPos);
            break;
        case "Piyon":
            updateAtMove(newPos);
            break;
        case "Sah":
            updateAtMove(newPos);
            break;
        case "Kale":
            updateAtMove(newPos);
            break;
        case "Fil":
            updateAtMove(newPos);
            break;
        default:
            cout << "Tas turu hatali." << endl;
            break;
        }
        */
    }
    else
    {
        cout << "Error:Move is not suitable!" << endl;
    }
}