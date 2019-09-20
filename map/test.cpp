#include <iostream>
#include <cassert>
#include "p2map2.h"
using namespace std;

int main()
{
    char K = '0';
    char V = '+', W = '=';
    Map<char,char> M;
    initialize(M,8);
    assign(M,K,V);
    assign(M,K,W);
    assert(M.table[0]->value == W);
}