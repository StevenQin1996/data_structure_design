#include <iostream>
#include <cassert>
#include "Tuple.h"
int main()
{
   Tuple<int> *a[1000];
    a[0] = new Tuple<int>(3);
    for (int i=1; i<1000; i++)
        a[i] = new Tuple<int>(*a[i-1]);
    
    for (int i=1; i<1000; i++) {
        assert(&a[i]->implementation() == &a[i-1]->implementation());
    }
    
    for (int i=0; i<1000; i++) {
        assert(a[i]->implementation().useCount() == 1000-i);
        delete a[i];
    }

    a[0] = new Tuple<int>(4);
    for (int i=1; i<1000; i++)
        a[i] = new Tuple<int>(*a[i-1]);
    for (int i=1; i<1000; i++) {
        assert(&a[i]->implementation() == &a[i-1]->implementation());
    }

    Tuple<int> b(4);
    for (int i=0; i<1000; i++) {
        *a[i] = b;
        assert(b.implementation().useCount() == i+2);
    }
    
    for (int i=0; i<1000; i++) {
        assert(a[i]->implementation().useCount() == 1000-i+1);
        delete a[i];
    }
    assert(b.implementation().useCount() == 1);
}