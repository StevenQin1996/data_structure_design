#include <iostream>
#include "IntegerQueue.h"
using namespace std;

IntegerQueue::IntegerQueue()//constructor
{
	length = 2;
	data = new int[length];
	head=0;
	tail=0;
}

IntegerQueue::~IntegerQueue()//destructor
{
	delete [] data;
}

void IntegerQueue::push(int n)//push a integer into this IntegerQueue(wrapping Queue), check the condition when it is full double the size of the array.
{
    if (size() == length-1)
    {
        int* stupid = new int[length*2];
    
        for (int x=0; x < length; x++)
        {
            stupid[x]= data[head++];

            if (head == length)
                head=0;
        } 
        tail = length-1;
        head = 0;
        length = length * 2;

        delete [] data;
        data = stupid;
    }

    data[tail]= n;
    tail++;
    
    if (tail==length )
    {
        tail=0;
    }
}

int IntegerQueue::pop()//pop from the IntegerQueue
{
    int store=data[head];
    head++;
    if (head==length)
    {
        head=0;
    }
    return store;
}

int IntegerQueue::size()const//this function will record how many value the Integetqueue contains.
{
    int count=0;
    if(tail>=head)
        count = tail-head;
    else
        count = tail+ (length - head);
     return count;
}

bool IntegerQueue::empty()const//check whether the IntegerQueue is empty
{
    return (size()==0);
}

IntegerQueue::IntegerQueue(const IntegerQueue& copy)// copy constructor which is used to initialize a previously uninitialized object from some other object's data
{
    this -> data = new int[copy.length]; 

    for(int counter = 0; counter<copy.length; counter++)//copy every data to IntegerQueue copy
    {
        this -> data[counter] = copy.data[counter];
    }

    this -> length = copy.length;
    this -> tail = copy.tail;
    this -> head = copy.head;
}

IntegerQueue IntegerQueue:: operator = (const IntegerQueue& Copycat)//assignment operator which is used to replace the data of a previously initialized object with some other object's data.
{
    if (this == &Copycat)//when something like IntegerQueue p(p) happens;
        return *this;

   
    int *temp = new int[Copycat.length];
    delete[] this->data;
    this -> data = temp;

    
    for( int counter = 0; counter<Copycat.length; counter++)//copy data over.
    {
        this ->data[counter] = Copycat.data[counter];
    }
    
    this ->length = Copycat.length;
    this -> tail = Copycat.tail;
    this -> head = Copycat.head;
    return *this;
} 

std::ostream& operator<<(std::ostream& lhs , const IntegerQueue& rhs)//name ostream and print out IntegerQueue. 
{
    
    lhs<<"{";
    if(!rhs.empty())//if rhs is empty, there should not be any number in side the {};
    {
        for (int counter = 0; counter<rhs.size()-1; counter++)
        {
            lhs<< rhs.data[counter]<<",";
        }
        lhs<<rhs.data[rhs.size()-1];
    }
    lhs<<"}";
    return lhs;
}

