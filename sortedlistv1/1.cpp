   #include <iostream>
    #include <cassert>
    #include "p2sortedlist1.h"
    using namespace std;
    
    int main()
    {
        SortedList<int> S;
        initialize(S);
        addItem(S,13);
        assert(S.list[0] == 13);
        assert(getKth(S,1) == 13);
    
        addItem(S,20);
        assert(S.list[0] == 13);
        assert(S.list[1] == 20);
    
        addItem(S,8);
        assert(S.list[0] ==  8);
        assert(S.list[1] == 13);
        assert(S.list[2] == 20);
        assert(getKth(S,1) ==  8);
        assert(getKth(S,3) == 20);
    
        // Add more function calls and assertions 
    }