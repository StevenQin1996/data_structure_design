#include <iostream>
#include "IntegerQueue.h"
using namespace std;

IntegerQueue::IntegerQueue()
{
	length = 2;
	data = new int[length];
	head=0;
	tail=0;
}

IntegerQueue::~IntegerQueue()
{
	delete [] data;
}

void IntegerQueue::push(int n)
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

int IntegerQueue::pop()
{
    int temp=data[head];
    head++;
    if (head==length)
    {
        head=0;
    }
    return temp;
}

int IntegerQueue::size()
{
    int count=0;
    if(tail>=head)
        count = tail-head;
    else
        count = tail+ (length - head);
     return count;
}

bool IntegerQueue::empty()
{
    return (size()==0);
}

int main()
{
    IntegerQueue q;
    cout << (q.empty() ? "q is empty":"q is not empty") << endl;
    q.push(3);
    q.push(4);
    q.push(2);
    cout << q.pop() << endl;
    cout << "q.size = " << q.size() << endl;
    cout << (q.empty() ? "q is empty":"q is not empty") << endl;
}