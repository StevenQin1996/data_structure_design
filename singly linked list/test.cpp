#include <cstddef>

// List is made up of linked Nodes
template <class T>
struct Node {
    T data;
    Node<T>* next;
};

// User knows about List, not Node
// A List is just a pointer to the head node (or NULL, if empty)
template <class T>
struct List {
    Node<T>* head;
};

// Initially set head to NULL, to indicate empty list
template <class T>
void initialize(List<T>& L)
{
    L.head = NULL;
}

// Deallocate all memory, leave head = NULL
template <class T>
void destroy(List<T>& L)
{
    // Deallocate every node in list
    // When complete, head will be NULL
    while( L.head != NULL )
    {
        Node<T>* p = L.head->next;
        delete L.head;
        L.head = p;
    }
}

template <class T>
void append(List<T>& L, T value)
{
    // Allocate memory and assign value for new Node
    Node<T>* newNode = new Node<T>;
    newNode->data = value; // (*newNode).data = value;
    newNode->next = NULL;
    
    // Handle special case for empty list
    if( L.head == NULL )
    {
        L.head = newNode;
        return;
    }
    
    // Get pointer to last node in list
    Node<T>* last = L.head;
    while( true ) // "walk" through list
    {
        if( last->next == NULL )
            break;
        last = last->next;
    }
    
    // Now last points to last node in list
    // Append newNode to end of list
    last->next = newNode;
}

template <class T>
bool contains(List<T> L, T value)
{
    Node<T>* walker = L.head;
    while( walker != NULL )
    {
        if( walker->data == value )
            return true;
        walker = walker->next;
    }
    // If loop ended, we reached end of list and assume value not present
    return false;
}

template <class T>
bool isEmpty(List<T> L)
{
    return L.head == NULL;
}

template <class T>
int  getSize(List<T> L)
{
    int n = 0;
    Node<T>* walker = L.head;
    while( walker != NULL )
    {
        n++;
        walker = walker->next;
    }
    return n;
}

// Assume list contains at least k elements
// Assume indexing starts at 1 (i.e., getKth(1) is head)
template <class T>
T getKth(List<T> L, int k)
{
    Node<T>* walker = L.head;
    for( int i = 1; i < k; i++ )
        walker = walker->next;
    return walker->data;
}

// Assume list contains at least k elements
// Assume indexing starts at 1
template <class T>
void removeKth(List<T>& L, int k)
{
    // Special case for deleting head node (k=1)
    if( k == 1 )
    {
        Node<T>* del = L.head;
        L.head = L.head->next;
        delete del;
        return;
    }

    // Find node before node to be deleted
    Node<T>* before = L.head;
    for( int i = 1; i < k-1; i++ )
        before = before->next;
    
    // before now points to node BEFORE node to be deleted
    Node<T>* del = before->next;
    
    // Re-route list "around" node to be deleted
    before->next = before->next->next; //del->next
    
    // Delete node
    delete del;
}