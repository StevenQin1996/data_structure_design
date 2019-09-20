#include<cstddef> // includes NULL definition

template <class T>
struct Stack {
   T*  data;	// array of values
   int size;	// size of array
   int top;	// index of value currently at top of Stack
};

template <class T>
void initialize(Stack<T>& S)
{
	S.size = 2;
	S.top = 0;
	S.data = new T[S.size];
}

template <class T>
void destroy(Stack<T>& S)
{
	delete [] S.data;
	S.data = NULL;
	S.size = 2;
	S.top = 0;
}

template <class T>
bool isEmpty(Stack<T> S)
{
	return(S.top == 0);
}

template <class T>
void push(Stack<T>& S, T value)
{
	
	if (S.top == S.size)
	{
		T* stupid = new T[S.size*2];

		for (int x=0; x<S.top; x++)
		{
			stupid[x] = S.data[x];
		}

		S.size = S.size*2;
		
		delete [] S.data;
		S.data = stupid;
	}
	
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