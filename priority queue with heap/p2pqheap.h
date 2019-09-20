// p2priorityqueue3.h

#include "p2heap.h"
#include <cstddef>

template <typename T>
struct Element 
{
    T   data;
    int priority;
    int order;
};

// Overload "<" operator to compare two elements, based on priority & order of entry
template <typename T>
bool operator<(Element<T> a, Element<T> b)
{
    // a has higher priority
    return   a.priority > b.priority 
        || ( a.priority == b.priority && a.order < b.order );
}

// Elements each have a unique order number, so no two are ever exactly equal
//  and it is sufficient to check if a < b
template <typename T>
bool operator<=(Element<T> a, Element<T> b)
{
    return (a < b); 
}

template <typename T>
bool operator>(Element<T> a, Element<T> b)
{
    return !(a<=b);
}

// Elements each have a unique order number, so no two are ever exactly equal
//  and it is sufficient to check if a > b
template <typename T>
bool operator>=(Element<T> a, Element<T> b)
{
    return (a > b); 
}

/*************************************************************/

// BEGIN PRIORITY QUEUE IMPLEMENTATION

template <typename T>
struct PriorityQueue
{
    Heap< Element<T> > h;
    int order;
};

template <typename T>
void initialize(PriorityQueue<T>& p)
{
    initialize(p.h,100); // initialize heap
    p.order = 0;     // start counting entries at zero
}

template <typename T>
void destroy(PriorityQueue<T>& p)
{
    destroy(p.h);
}

template <typename T>
bool isEmpty(PriorityQueue<T> p)
{
    // Priority Queue is empty when heap is empty
    return isEmpty(p.h);
}

template <typename T>
void push(PriorityQueue<T>& p, T value, int rank)
{
    // Create new element
    Element<T> e;
    e.data = value;
    e.priority = rank;
    e.order = p.order++;
    // Put element into heap
    put(p.h,e);
}

template <typename T>
T pop(PriorityQueue<T>& p)
{
    Element<T> e = get(p.h); // Get element from heap
    return e.data;         // Just return data (ignore priority & order)
}