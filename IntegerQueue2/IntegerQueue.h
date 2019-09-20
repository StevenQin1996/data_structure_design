#include <iostream>

class IntegerQueue
{
	friend std::ostream& operator<<(std::ostream&, const IntegerQueue&);
	
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
		int size()const;
		bool empty()const;
		IntegerQueue (const IntegerQueue&);
		IntegerQueue operator = (const IntegerQueue&);
		
};

