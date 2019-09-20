#include <iostream>
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
