#include <iostream>

#define CHESSLIB_HPP_

void printPosArray(struct position *);
void boardToArray(int, int, struct position);
void arrayToBoard(int, int, struct position);

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

public:
    Tas(){};
    Tas(struct position);
    ~Tas(){};
    void setPos(struct position);
    struct position getPos();
    void setMove(struct position *);
    struct position *getMove();
    friend void movePiece(Tas *, struct position);
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

