#include <iostream>
#include <iomanip>
#include <cassert>
#include "p2bst4.h"
using namespace std;

int main()
{
      int A =  5, B = 12, C = 17, D = 20, E = 32, F = 35, G = 36, H = 38, I = 39,
        J = 40, K = 41, L = 50, M = 80, N = 85, O = 90;
    int X = 34;
    Tree<int> T;
    initialize(T);
    insert(T,J);
    insert(T,O);
    insert(T,K);
    insert(T,E);
    insert(T,F);
    insert(T,M);
    insert(T,A);
    insert(T,B);
    insert(T,H);
    insert(T,L);
    insert(T,I);
    insert(T,D);
    insert(T,G);
    insert(T,N);
    insert(T,C);
    remove(T,X);
    remove(T,H);
    remove(T,B);
    remove(T,J);
    assert(countNodes(T) == 12);
}