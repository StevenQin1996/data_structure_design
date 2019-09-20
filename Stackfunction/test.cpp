#include <iostream>
#include <cassert>
#include "p2stackfunctions.h"
using namespace std;

int main()
{
    char A = 'A', B = 'B', C = 'C', D = 'D';

    Stack<char> S;
    initialize(S);

    // Push in some values, for testing    
    push(S,A);
    push(S,B);
    push(S,C);
    push(S,D);

    // Peek
    assert(peek(S) == D);
    assert(peek(S) == D); // shouldn't change top value
    pop(S);
    assert(peek(S) == C);
    assert(peek(S) == C);

    push(S,D);

    // Dup
    dup(S); // should duplicate D
    assert(pop(S) == D && pop(S) == D); // should pop two D's
    dup(S); // dup C
    assert(pop(S) == C && pop(S) == C);

    push(S,C);
    push(S,D);
   
    // flip
    flip(S);
    assert(pop(S) == C); // C should be top after flip
    assert(pop(S) == D); // D should have been shifted down one
    assert(peek(S) == B); // shouldn't have changed B
    flip(S);
    assert(pop(S) == A);
    assert(pop(S) == B);

    push(S,A);
    push(S,B);
    push(S,C);
    push(S,D);

    // roll
    roll(S,1); 
    assert(peek(S) == D); // roll 1 should have no effect
    roll(S,2);

    assert(pop(S) == C); // roll 2 should be comparable to flip
    assert(pop(S) == D);
    push(S,C);
    push(S,D);
    roll(S,3);
    assert(pop(S) == C);
    assert(pop(S) == B);
    assert(pop(S) == D);
    push(S,B);
    push(S,C);
    push(S,D);
    roll(S,4);

    for(int i = 0; i < S.top; i++)
        cout << S.data[i] << endl;
    cout << endl;
    roll(S,4);

    for(int i = 0; i < S.top; i++)
        cout << S.data[i] << endl;
    assert(pop(S) == B);
    assert(pop(S) == A);
    assert(pop(S) == D);
    assert(pop(S) == C);

    destroy(S);
}