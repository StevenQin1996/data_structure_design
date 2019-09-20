#include <iostream>
#include <cassert>
#include "p2set1.h"
using namespace std;

int main()
{
      int A = 12, B = 37, C = 8;
    Set<int> S;
    initialize(S);
    insert(S,A);
    insert(S,B);
    insert(S,A);
    assert(S.size == 2);   
}