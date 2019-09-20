#include <iostream>
#include <cassert>
#include "p2stack1.h"
using namespace std;

int main()
{
    char A = 'A', B = 'B', C = 'C', popped;

    Stack<char> S;
    initialize(S);
    
    assert(S.top == 0);
    assert(isEmpty(S));
    
    push(S,A);
    assert(S.data[0] == A);
    assert(S.top == 1);
    assert(!isEmpty(S));
    
    push(S,B);
    assert(S.data[0] == A);
    assert(S.data[1] == B);
    assert(S.top == 2);
    
    popped = pop(S);
    assert(popped == B);
    assert(S.data[0] == A);
    assert(S.top == 1);
    
    // Add more function calls and assertions 
}