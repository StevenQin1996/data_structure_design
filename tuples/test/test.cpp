
#include <iostream>
#include <cassert>
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
    /*Tuple<int> add(Tuple<int> a,Tuple<int> b,Tuple<int> c)
    {
       return a+b+c;     // allocation for 2 anonymous objects, deallocation for 1 of them
    }*/
      int x[3] = {1,2,3};
      int y[3] = {4,5,6};
      Tuple<int> a(x, 3);  // allocation of 3 ints
      Tuple<int> b(y,3);  // allocation of 5 ints
      Tuple<int> c(3);

      c = a;


      int S = b * a;
      cout<<S<<endl;

      Tuple<int> sum(a);
      sum = sum *3;
      print(sum);

      print(c);
       Tuple<int> d(a);
      cout << a.TD()->useCount() << endl;

      cout << b.TD()->useCount() << endl;
}