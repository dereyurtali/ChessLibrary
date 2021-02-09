#include <iostream>
#include "chessLib.hpp"

using namespace std;

int main()
{
    Tas **board = createTasArray(8, 8);
    Tas *black = createTasArray(16);
    Tas *white = createTasArray(16);

    struct position a1;
    a1.dusey = 'a';
    a1.yatay = 1;
    Kale kSol(a1);
    white = &kSol;

    struct position b1;
    b1.dusey = 'b';
    b1.yatay = 1;
    At atSol(b1);
    

    struct position c1;
    c1.dusey = 'c';
    c1.yatay = 1;
    Fil filSol(c1);

    struct position d1;
    d1.dusey = 'd';
    d1.yatay = 1;
    Sah sahBeyaz(d1);

    struct position e1;
    e1.dusey = 'e';
    e1.yatay = 1;
    Vezir vezirBeyaz(e1);

    struct position f1;
    f1.dusey = 'f';
    f1.yatay = 1;
    Fil filSag(f1);

    struct position g1;
    g1.dusey = 'g';
    g1.yatay = 1;
    At atSag(g1);

    struct position h1;
    h1.dusey = 'h';
    h1.yatay = 1;
    Kale kaleSag(h1);

    struct position a2;
    a2.dusey = 'a';
    a2.yatay = 2;
    Piyon p1(a2);
    struct position b2;
    b2.dusey = 'b';
    b2.yatay = 2;
    Piyon p2(a2);
    struct position c2;
    c2.dusey = 'c';
    c2.yatay = 2;
    Piyon p3(a2);
    struct position d2;
    d2.dusey = 'd';
    d2.yatay = 2;
    Piyon p4(d2);
    struct position e2;
    e2.dusey = 'e';
    e2.yatay = 2;
    Piyon p5(e2);
    struct position f2;
    f2.dusey = 'f';
    f2.yatay = 2;
    Piyon p6(f2);
    struct position g2;
    g2.dusey = 'g';
    g2.yatay = 2;
    Piyon p7(g2);
    struct position h2;
    h2.dusey = 'h';
    h2.yatay = 2;
    Piyon p8(h2);

    return 0;
}