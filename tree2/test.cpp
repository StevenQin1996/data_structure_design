#include <iostream>
#include <iomanip>
#include "p2bst3.h"
#include <cassert>
using namespace std;

int main()
{
   char A = 'A', B = 'B', C = 'C';
   Tree<char> T;
   initialize(T);
   insert(T,B);
   insert(T,A);
   insert(T,C);
   assert(countSingle(T) == 0);
}