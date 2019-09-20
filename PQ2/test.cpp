#include <iostream>
#include <cassert>
#include "p2priorityqueue2.h"
using namespace std;

int main()
{
     int V;
    PriorityQueue<int, int> PQ;
    initialize(PQ);
    push(PQ,1,4);
    //cout<< PQ.head;
    push(PQ,2,4);
    //cout<< PQ.head;
    push(PQ,3,6);
    //cout<<PQ.head;
    assert(PQ.head != NULL);
}