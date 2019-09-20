  #include <iostream>
using namespace std;
    
    // Contains sorted values in array list, indexed 0..count-1
    // You may assume that no more than 100 values will be added
    template <class T>
    struct SortedList {
        T list[100]; // contains sorted values, index range 0..count-1
        int count;  // indicates current number of values
    };
    
    // Initializes struct to contain no values (have zero count)
    template <class T>
    void initialize(SortedList<T>& sl)
    {
        sl.count=0;
    }
    
    // Add given value to list, placing it in correct sorted order
    // You may assume that the values are comparable
    template <class T>
    void addItem(SortedList<T>& sl, T value)
    {

            sl.list[sl.count] = value;
            sl.count ++;
       
       for (int j = 0; j < sl.count; j++)
        {
            T lowest = sl.list[j];
            for (int i = j; i < sl.count; i++)
            {
             if (sl.list[i] < lowest)
                {
                    lowest = sl.list[i];
                    T temp = sl.list[j];
                    sl.list[j] = lowest;
                    sl.list[i] = temp;
                }
            }
        }
    }

    
    // Return Kth value from list (e.g., 1st, 2nd, etc.)
    // You may assume that there are at least K values in the list
    template <class T>
    T getKth(SortedList<T> sl, int k)
    {      
       return sl.list[k-1];
    }
    
    // Output list contents, comma-separated, all on one line, in sorted order
    // Example: 1, 2, 3, 5, 8, 9, 11
    // You may assume that each value is printable
    template <class T>
    ostream& operator<< (ostream& out, SortedList<T> sl)
    {
        for ( int x=0; x<sl.count-1; x++)
        {
            out<<sl.list[x]<<", ";
        }
        out <<sl.list[sl.count-1];
        return out;
    }