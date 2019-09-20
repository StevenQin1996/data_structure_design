#include<cstddef>

template <class T>
struct Node {
   T value;
   Node<T>* next;
};

template <class T>
struct Stack {
   Node<T>* top;
};

template <class T>
void initialize(Stack<T>& S)
{
	S.top = NULL;
}

template<class T>
void destroy(Stack<T>& S)
{
	while(S.head -> next =! NULL)
	{
		Node<T>* P = S.head;
		S.head = S.head -> next;
		delete P;
	}
	initialize(S);
}

template<class T>
bool isEmpty(Stack<T> S)
{
	return (S.top == NULL);
}

template <class T>
void push(Stack<T>& S,T value)
{
	Node<T>* newnode = new Node<T>; 
	newnode -> value = value;
	newnode -> next = NULL;
		
	if (isEmpty(S))
	{
		S.top -> value = newnode;
		S.top ->next = NULL;
	}
	else
	{
		while (true)
		{
			Node<T>* P = new Node;
			P -> value = S.top;
			S.top -> value = newnode;
			newnode -> next = P;
		}
	}
}

template<class T>
T    pop(Stack<T>& S)
{
	T aldo = S.top -> value;
	Node<T>* X = S.top;
	S.top = S.top -> next;
	delete X;
	return aldo;
}