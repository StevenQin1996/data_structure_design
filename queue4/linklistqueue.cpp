#include <fstream>
#include <cstddef>

template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template <typename T>
struct Queue {
    Node<T>* head;
    Node<T>* tail;
};

template <typename T>
void initialize(Queue<T> &q)
{
    q.head = NULL;
    q.tail = NULL;
}

template <typename T>
void destroy(Queue<T> &q)
{
    // Deallocate queue memory (if any)
    Node<T>* np = q.head;
    while( np != NULL )
    {
        Node<T>* t = np;
        np = np->next;
        delete t;
    }
    q.head = NULL;
    q.tail  = NULL;
}

template <typename T>
bool isEmpty(Queue<T> q)
{
    return (q.head == NULL);
}

template <typename T>
void push(Queue<T> &q, T n)
{
    Node<T>* tmp = new Node<T>;
    tmp->value = n;
    tmp->next = NULL;
    
    if( isEmpty(q) )
    {
        q.head = tmp;
        q.tail = tmp;
    }
    else
    {
        q.tail->next = tmp;
        q.tail = tmp;
    }    
}

template <typename T>
T pop(Queue<T> &q)
{
    T r = q.head->value;
    Node<T>* f = q.head->next;
    delete q.head;
    q.head = f;
    if( q.head == NULL ) // queue empty
        q.tail = NULL; 
    return r;
}