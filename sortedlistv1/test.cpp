    #include <iostream>
    #include "p2sortedlist1.h"
    using namespace std;
    
    int main( )
    {
        SortedList<char> clst;
        initialize(clst);
    
        addItem(clst,'J');
        addItem(clst,'E');
        addItem(clst,'Z');
        addItem(clst,'M');
    
        cout << clst << endl;
    
        addItem(clst,'B');
        addItem(clst,'C');
        addItem(clst,'K');
    
        cout << clst << endl;
    
        SortedList<double> dlst;
        initialize(dlst);
    
        addItem(dlst,1.7);
        addItem(dlst,3.2);
        addItem(dlst,2.4);
        addItem(dlst,2.7);
        addItem(dlst,1.1);
    
        cout << dlst << endl;
    }