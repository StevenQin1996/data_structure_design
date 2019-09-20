#include <iostream>
#include "p2queue1.h"
using namespace std;

int main()
{   
   Queue<int> q;
   initialize(q);
    
   cout << "This program tests a queue implementation.\n\n";
    
   string command;
   int value;
   while(true)
   {
      cin >> command;
        
      if( command == "Quit" )
         break;
        
      if( command == "Push" ) 
      {
         cin >> value;
         push(q,value);
      }
        
      if( command == "Pop" )
      {
         if( isEmpty(q) )
            cout << "-- Queue empty\n";
         else
            cout << ">> " << pop(q) << endl;
      }
   }    
   destroy(q);
}