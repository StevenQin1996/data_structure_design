#include <iostream>
#include <iomanip>

using namespace std;

const int MAXSIZE = 5;
	
template <class T>
struct Stack {
   T   data[MAXSIZE];
   int top;
};
	
template <class T>
void initialize(Stack<T>& S)
{
	S.top=0;
}

template <class T>
void destroy(Stack<T>& S)
{
	initialize(S);
}

template <class T>
bool isEmpty(Stack<T> S)
{
	return (S.top==0);
}

template <class T>
void push(Stack<T>& S, T value)
{
	S.data[S.top]= value;
	S.top++;
}

template <class T>
T    pop(Stack<T>& S)
{
	S.top--;
	T temp=S.data[S.top];
	
	return temp;
}

template <class T>
T peek(Stack<T> S)
{
	S.top--;
	T temp=S.data[S.top];
	
	return temp;
}

template <class T>
void dup(Stack<T>& S)
{
	S.data[S.top]=S.data[S.top-1];
	S.top++;
	
}

template <class T>
void flip(Stack<T>& S)
{
	T temp=S.data[S.top-1];
	S.data[S.top-1]=S.data[S.top-2];
	S.data[S.top-2]=temp;
}

template <class T>
void roll(Stack<T>& S, int value)
{
	int count=S.top-1;
	for (int n=1; n<value; n++)
	{
		T temp=S.data[count];
		S.data[count]=S.data[count-1];
		S.data[count-1]=temp;
		count--;
	}	
}

