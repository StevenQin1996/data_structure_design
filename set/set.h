#include <cstddef>
#include <iostream>
using namespace std;

template <class T>
struct Set {
    T* data;
    int size;        
    int count;
};

void initialize(Set<T>&);
void destroy(Set<T>&);
bool isEmpty(Set<T>);
void insert(Set<T>&, T value);
bool contains(Set<T>, T value);
void remove(Set<T>&, T value);
int  getSize(Set<T>);     
