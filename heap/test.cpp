#include <iostream>
#include <cassert>
#include "p2heap.h"
using namespace std;

int main()
{
    float A = 6.5, B = 9, C = 10, D = 30, E = 16, F = 2, G = 31, H = 40, I = 25, S;
   Heap<float> T;
   initialize(T,100);
   put(T,A);
   cout<<A;
   put(T,B);
   cout<<B;
   put(T,C);
   cout<<C;
   put(T,D);
   cout<<D;
   put(T,E);
   cout<<E;
   put(T,F);
   cout<<F;
   put(T,G);
   cout<<G;
   put(T,H);
   cout<<H;
   put(T,I);
   cout<<I;
   S = get(T);
   cout<<S<<endl;
   cout<<get(T);
   assert(S == F);
   S = get(T);
   S = get(T);
}