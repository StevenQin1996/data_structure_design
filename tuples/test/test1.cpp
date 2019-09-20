//#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
#include <iostream>
#include <cassert>
//#include <array>
#define DEBUG
#include "Tuple.h"
using namespace std;


void print(Tuple<int> t){

  for(int i = 0; i < t.size(); i++){

    cout << t[i] << ", ";
  }
  cout << endl;
}

int main()
{
    int data[] = {2,3,5,7,11,13,17,19,23};
    Tuple<int> a(data,9);
    Tuple<int> b(data,3);
    Tuple<int> c = a + b;
    for (int i=0; i<9; i++) {
    }
    cout<<a.implementation().useCount();
    assert(a.implementation().useCount()==1);
}