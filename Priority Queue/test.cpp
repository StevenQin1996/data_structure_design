#include <iostream>
#include <cassert>
#include "p2priorityqueue1.h"
using namespace std;

int main()
{
    char A = 'A', B = 'B', C = 'C', popped;

    PriorityQueue<char> PQ;
    initialize(PQ);
    
    assert(isEmpty(PQ));
    
    push(PQ,A,5);
    assert(!isEmpty(PQ));
    assert(getSize(PQ) == 1);

    push(PQ,B,7);
    push(PQ,C,5);
    
    popped = pop(PQ);
    assert(popped == B); // highest priority
    
    popped = pop(PQ);
    assert(popped == A); // two of equal priority, but A longer in PQ
    assert(!isEmpty(PQ));
    
    // Add more function calls and assertions 
}