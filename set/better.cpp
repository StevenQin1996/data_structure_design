// p2set1.h

#include <cstddef>

template <typename T>
struct Set {
    T* data;
    int size;
    int count;
};

template <typename T>
void initialize(Set<T> &s) {
    s.size = 2;
    s.data = new T[s.size];
    s.count = 0;
}

template <typename T>
void destroy(Set<T>& s) {
    s.count = 0;
    s.size = 0;
    delete [] s.data;
    s.data = NULL;
}

template <typename T>
bool contains(Set<T> s, T v) {
    for( int i = 0; i < s.count; i++ )
        if( s.data[i] == v )
            return true;
    return false;
}

template <typename T>
void insert(Set<T> &s, T v) {
    // If value is already in Set, return (trivially, insert is successful)
    if( contains(s,v) )
        return;
    // Else, add new value to array
    // Need to increase size of array?
    if( s.count == s.size ) {
        T* tmp = s.data;                     // point to current array
        s.data = new T[s.size*2];            // allocate new array
        for( int i = 0; i < s.size; i++ )    // copy into new array
            s.data[i] = tmp[i];    
        delete [] tmp;                       // deallocate old array
        s.size *= 2;                         // twice size of old array
    }    
    // Add new value to end of array and increment count
    s.data[s.count++] = v; 
}

template <typename T>
void remove(Set<T> &s, T v) {
    // Search array; if value found, remove and shift last value to new open space
    for( int i = 0; i < s.count; i++ )
        if( s.data[i] == v )
        {
            s.data[i] = s.data[--s.count];   // move last value here, decrement count
            return;
        }    
}

template <typename T>
int getSize(Set<T> s) {
    return s.count;
}

template <typename T>
bool isEmpty(Set<T> s) {
    return (getSize(s) == 0);
}
