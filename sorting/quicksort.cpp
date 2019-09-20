#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* walker)
{
    while( walker != NULL )
    {
        cout << walker->data;
        walker = walker->next;
        cout << ( walker != NULL ? ", " : "\n" );
    }
}

void addItem(Node* &head, int newitem)
{
    Node* n = new Node;
    n->data = newitem;
    n->next = NULL;
    
    // list currently empty
    if( head == NULL )    
    {
        head = n;
    }
    else // list currently non-empty
    {
        Node* walker = head;
        while( walker->next != NULL )
            walker = walker->next;
        walker->next = n;
    }
}

Node* quicksort(Node* head)
{
    // If list is empty or length 1, already sorted
    if( head == NULL || head->next == NULL )
        return head; // return head of sorted list
        
    // Otherwise, split into 3 lists based on pivot
    Node* less = NULL;
    Node* equal = NULL;
    Node* greater = NULL;
    
    // Select first value as pivot
    int pivot = head->data;
    
    Node* walker = head;
    while( walker != NULL )
    {
        Node* p = walker; // pointer to current Node
        walker = walker->next; // point to next Node
        
        if( p->data < pivot )
        {
            p->next = less;
            less = p;
        }
        else if( p->data == pivot )
        {
            p->next = equal;
            equal = p;
        }
        else // p->data > pivot
        {
            p->next = greater;
            greater = p;
        }
    }
    
    // Recursively sort sublists
    Node* sortedLess = quicksort(less);
    Node* sortedGreater = quicksort(greater);
    
    // Connect sublists in correct order
    if( sortedLess != NULL )
    {
        walker = sortedLess;
        while( walker->next != NULL )
            walker = walker->next;
        walker->next = equal;
    }
    walker = equal;
    while( walker->next != NULL )
        walker = walker->next;
    walker->next = sortedGreater;
    
    // return head of sorted list
    return ( sortedLess != NULL ? sortedLess : equal );
}

int main()
{
    srand(time(NULL));
    
    Node* head = NULL;
    int size;
    
    cout << "How many values? ";
    cin >> size;
    cout << endl;
    
    /** RANDOM **/
    int x;
    for( int i = 0; i < size; i++ ) {
        addItem( head, rand() % (size*10) );
    }
    
    /** ORDERED **
     for( int i = 0; i < size; i++ ) {
        addItem( head, i );
     }
     */
    
    /** REVERSE **
     for( int i = 0; i < size; i++ ) {
        addItem( head, size-i );
     }
     */    

    cout << "Unsorted list: ";
    printList(head); // print unsorted    
    
    Node* sorted = quicksort(head);
    
    cout << "Sorted list:   ";
    printList(sorted); // print sorted, hopefully
    
    // Deallocate
    Node* t; 
    while( sorted != NULL )
    {
        t = sorted->next;
        delete sorted;
        sorted = t;
    }
}