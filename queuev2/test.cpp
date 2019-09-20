#include <iostream>
#include <cassert>
#include "p2queue2.h"
using namespace std;

int main()
{
     int A = 5, B = 7, C = 4, D = 6, E = 0, F;
    Queue<int> Q;
    initialize(Q);
    push(Q,A);
    push(Q,B);
    push(Q,C);
    push(Q,D);
    F = pop(Q);
    push(Q,E);
    assert(getSize(Q) == 4);
    
    // Add more function calls and assertions 
}