#include <iostream>

class IntegerQueue
{
	private: 
		int length;
		int head;
		int tail;
		int *data;//shift every five hundred times.
	
	public:

		IntegerQueue();
		~IntegerQueue();
		void push(int n);
		int pop();
		int size();
		bool empty();
	
};

