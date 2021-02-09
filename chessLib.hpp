#include <iostream>

#define CHESSLIB_HPP_

using namespace std;

void printPosArray(struct position *);
struct ij boardToArray(struct position);
struct position arrayToBoard(struct ij);

struct ij
{
    short i;
    short j;
};

struct position
{
    char dusey;
    short yatay;
};

struct position *updateSahMove(struct position);
struct position *updateVezirMove(struct position);
struct position *updateFilMove(struct position);
struct position *updateAtMove(struct position);
struct position *updateKaleMove(struct position);
struct position *updatePiyonMove(struct position);

class Tas
{
private:
    struct position pos;
    struct position *move;
    string tasTuru;

public:
    Tas(){};
    Tas(struct position);
    ~Tas(){};
    void setPos(struct position);
    struct position getPos();
    void setMove(struct position *);
    struct position *getMove();
    void setTasTuru(string);
    string getTasTuru();
    friend void movePiece(Tas *, struct position);
    //friend Tas **createTasArray(int, int);
    //friend Tas *createTasArray(int);
};

class Sah : public Tas
{
public:
    Sah(){};
    Sah(struct position);
    ~Sah(){};
    void printPiece(void);
};

class Vezir : public Tas
{
public:
    Vezir(){};
    Vezir(struct position);
    ~Vezir(){};
    void printPiece(void);
};

class Fil : public Tas
{
public:
    Fil(){};
    Fil(struct position);
    ~Fil(){};
    void printPiece(void);
};

class At : public Tas
{
public:
    At(){};
    At(struct position);
    ~At(){};
    void printPiece(void);
};

class Kale : public Tas
{
public:
    Kale(){};
    Kale(struct position);
    ~Kale(){};
    void printPiece(void);
};

class Piyon : public Tas
{
public:
    Piyon(){};
    Piyon(struct position);
    ~Piyon(){};
    void printPiece(void);
};
Tas **createTasArray(int, int);
Tas *createTasArray(int);