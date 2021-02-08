#include <iostream>

#define CHESSLIB_H_

struct position
{
    char dusey;
    short yatay;
};
class Tas
{
private:
    struct position pos;
    struct position *move;

public:
    Tas();
    Tas(struct position);
    ~Tas();
    void setPos(struct position);
    struct position getPos();
    void setMove(struct position *);
    struct position *getMove();
};


class Sah : Tas
{
public:
    Sah();
    Sah(struct position);
    ~Sah();
    void printPiece(void);
};


class Vezir : Tas
{
public:
    Vezir();
    Vezir(struct position);
    ~Vezir();
    void printPiece(void);
};


class Fil : Tas
{
public:
    Fil();
    Fil(struct position);
    ~Fil();
    void printPiece(void);
};


class At : Tas
{
public:
    At();
    At(struct position);
    ~At();
    void printPiece(void);
};


class Kale : Tas
{
public:
    Kale();
    Kale(struct position);
    ~Kale();
    void printPiece(void);
};


class Piyon : Tas
{
public:
    Piyon();
    Piyon(struct position);
    ~Piyon();
    void printPiece(void);
};

void arrayToChess(int, int, struct position);

Tas **board = (Tas **)malloc(8* sizeof(Tas *));
for(int i = 0; i < 8; i++) {
    board[i] = (Tas *)malloc(8* sizeof(Tas));
}
